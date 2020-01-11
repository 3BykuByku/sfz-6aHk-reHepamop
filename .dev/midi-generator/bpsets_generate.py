#!/usr/bin/env python

# bpsets 2.0.3 --
# Pitch Class Sets for Python, BOHLEN-PIERCE EDITION.
#
# Copyright 2008 Bruce H. McCosar
#
# This file is part of the package 'bpsets' (a derivative of my
# original module, 'pcsets-2.0.3').
#
# The package 'bpsets' is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 3 of
# the License, or (at your option) any later version.
#
# The package 'pcsets' is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#
# $Id: bpsets.py 37 2008-04-27 00:50:13Z mccosar $
#

__metaclass__ = type

__all__ = """
common
DefinitionError
exact_equality
fit_in
harmonize
IllegalCharacter
is_complement
is_prime_complement
NonIterableDef
NullOpSet
op_path
OpSet
OpSetError
PcSet
PcSetException
prime_subset_of
R0
R1
R2
rel_Tn
rel_TnI
Rp
Rp_path
Rp_prime
same_prime
SetCatalog
set_equality
showcatalog
subset_of
symmetry
union
Zpair
""".split()

"""
PcSets: Pitch Class Sets for Python -- Bizarro World Version.

Bruce H. McCosar

This module is a derivative of my original module, pcsets-2.0.2.
I have adapted it to the Bohlen-Pierce Scale.

The BP scale is mod 13.  Therefore, the permissible numeric
values are 0 through 12.  I have chosen to represent each
pitch class value as a single character -- 0 to 9 for the
digits, then A=10, B=11, C=12.  This makes specification of
BP pitch class sets much more compact and readable (to me,
anyway).  However these can also be accessed as a list of
numeric values, or, indeed, passed through the converter
of your choice into your preferred format.

Most of the work I've seen on pitch class sets assumes
you are in 12-TET.  Adapting this to BP means ... I've got
a free hand for interpretation.  My preferred option!

References:

1. The Bohlen-Pierce Site

    http://members.aol.com/bpsite/
    
2. PcSets (Google Code)

    http://code.google.com/p/pcsets/
    
3. About Pitch Class Sets (General)

    http://www.jaytomlin.com/music/settheory/help.html

$Id: bpsets.py 37 2008-04-27 00:50:13Z mccosar $
"""

class PcSetException(Exception):
    """
    The base class for exceptions in the pcset family of modules.
    """
    def __init__(self):
        self.message = self.__doc__

    def __str__(self):
        return self.message


class DefinitionError(PcSetException):
    """
    This exception type is thrown when something goes wrong in defining a
    PcSet (creating a PcSet instance). Any exception that occurs during
    definition will be a subclass of this.
    """


class IllegalCharacter(DefinitionError):
    """
    When defining a PcSet as a specification string, the only legal
    characters are the digits 0-9 and the capital letters A to C.
    The first illegal character encountered was: %(illegal)s
    """
    def __init__(self,ch):
        self.message = self.__doc__ % {'illegal' : ch}


class NonIterableDef(DefinitionError):
    """
    When defining a PcSet, the definition must be an iterable type
    such as a list, set, tuple, or string. In this case, something
    non-iterable was encountered:

    problem input = %(problem)s %(classification)s
    """
    def __init__(self,x):
        trouble = {
            'problem' : x,
            'classification' : type(x)
            }
        self.message = self.__doc__ % trouble


def moderate(x):
    try:
        n = int(x)
    except ValueError:
        if x == 'A':
            n = 10
        elif x == 'B':
            n = 11
        elif x == 'C':
            n = 12
        else:
            raise IllegalCharacter(x)
    return n % 13


def binaryvalue(i):
    value = 0
    for bit in i:
        value += 2**bit
    return value


class PcSet:

    """
    Pitch Class Set. Once defined, the set can be manipulated using the
    supplied methods, which are grouped into the following categories:

    FUNDAMENTAL METHODS
        invert()
        transpose(n)
        
    SET OPERATIONS
        complement()
        reverse()
        sort()
        shift(n)
        zero()
        normal()
        reduced()
        prime()
        
    SET ANALYSIS
        ivec()
        cvec()
        
    SHORTHAND METHODS
        I()
        T(n)
        TnI(n)
        Ixy(x,y)

    In addition, PcSets have default string, length, and iterator methods,
    making possible calls such as len(pcs), str(pcs), and list(pcs).

    A useful reference for understanding pc sets:
    http://www.jaytomlin.com/music/settheory/help.html    
    """

    # basic services

    def __init__(self,definition):
        """
        A PcSet may be defined as a spec string or as a list. If a string is
        entered, the only characters allowed are 0-9 and A-C (A represents
        10, B=11, C=12). If a problem is encountered with the input to the
        constructor, a DefinitionError is raised.
        """
        try:
            redefinition = [moderate(note) for note in list(definition)]
        except TypeError:
            # non-iterables go here
            raise NonIterableDef(definition)
        self.definition = []
        for note in redefinition:
            # remove duplicates
            if note not in self.definition:
                self.definition.append(note)

    def __iter__(self):
        for note in self.definition:
            yield note

    def __str__(self):
        output = ''
        for x in self:
            if x < 10:
                output += str(x)
            elif x == 10:
                output += 'A'
            elif x == 11:
                output += 'B'
            elif x == 12:
                output += 'C'
        return output

    def __len__(self):
        return len(self.definition)

    # fundamental methods

    def invert(self):
        """
        Returns a new PcSet which is the inverse of the original.
        """
        inverse = [((13-note) % 13) for note in self]
        return PcSet(inverse)

    def transpose(self,n):
        """
        Returns a new PcSet which is the original transposed by n.
        """
        transposed = [((note+n) % 13) for note in self]
        return PcSet(transposed)

    # set operations

    def complement(self):
        """
        Returns a new PcSet which is the complement of the original set -- it
        contains all the elements which the original does not.
        """
        anti = []
        for note in range(13):
            if note not in self:
                anti.append(note)
        return PcSet(anti)

    def reverse(self):
        """
        Returns a new PcSet with the elements of the original reversed.
        """
        return PcSet(reversed(self.definition))

    def sort(self):
        """
        Returns a new PcSet in which the elements of the original have been
        sorted in ascending order.
        """
        return PcSet(sorted(self))

    def shift(self,n):
        """
        Returns a new PcSet in which the elements of the original have been
        shifted up 'n' places. (Negative values for n shift down instead; zero
        does nothing but return a copy.)
        """
        size = len(self)
        copy = list(self)
        if size > 1:
            uptimes = int(n) % size
            if uptimes > 0:
                for x in range(uptimes):
                    copy.insert(0,copy.pop())
        return PcSet(copy)

    def zero(self):
        """
        Returns a new PcSet in which the elements have been transposed so that
        the first element is zero.
        """
        try:
            return self.transpose(-self.definition[0])
        except IndexError:
            # empty set, no first element
            return PcSet(self)

    def normal(self):
        """
        Returns a new PcSet which is the 'normal form' of the original. The
        normal form has elements arranged to take up smallest total interval
        space from beginning to end. In the case of ties, the arrangement with
        the best 'packing' toward the left is chosen.
        """
        size = len(self)
        if size < 2:
            return PcSet(self)
        # determine all the possible shift rotations of the sorted set
        original = self.sort()
        rotations = [original.shift(n) for n in range(size)]
        # determine which arrangement has the lowest binary value
        # when compared from a fair start (first element on zero)
        bestnormal = rotations.pop()
        established = binaryvalue(bestnormal.zero())
        for arrangement in rotations:
            challenger = binaryvalue(arrangement.zero())
            if challenger < established:
                bestnormal = arrangement
                established = challenger
        return bestnormal

    def reduced(self):
        """
        Returns a new PcSet which is the 'reduced form' of the original.
        For a given PcSet 'pcs', this is equivalent to the operation series

            pcs.normal().zero()

        The returned set will be easily comparable to other reduced sets.
        """
        return self.normal().zero()

    def prime(self):
        """
        Returns a new PcSet which is the 'prime form' of the original.
        The prime form can be transformed into any of the sets in its
        'family' through the operations T(n) and T(n)I.

        Any set will have a normal form.  If the set is transposed so that
        the first element is zero, this is the reduced form.  However, any
        set will also have an inversion.  The reduced form of the inversion
        can be compared to the original reduced form.  The prime form,
        then, is the reduced set that has the closest leftward packing.
        """
        original = self.normal().zero()          # reduced form
        inverted = self.invert().normal().zero() # reduced form of inverse
        if binaryvalue(original) < binaryvalue(inverted):
            return original
        else:
            return inverted

    # set analysis

    def ivec(self):
        """
        Finds the Interval Vector for the set.
        """
        ivec = [0] * 7
        workingcopy = list(self.sort())
        while len(workingcopy) > 1:
            note = workingcopy.pop()
            for othernote in workingcopy:
                intervalclass = (note - othernote) % 13
                if intervalclass > 7:
                    intervalclass = (13 - intervalclass) % 13
                ivec[intervalclass-1] += 1
        return ivec        

    def cvec(self):
        """
        Common Tone Vector: finds the number of common tones for each possible
        value of n in the operation TnI. Returns a twelve member vector where
        element 0 is the number of common tones under T(0)I, 1 under T(1)I,
        and so on.
        """
        cvec = [0] * 13
        rawtable = []
        for x in self:
            for y in self:
                rawtable.append((x+y) % 13)
        entries = set(rawtable)
        for value in entries:
            cvec[value] += rawtable.count(value)
        return cvec

    # shorthand methods

    def I(self):
        """
        Shorthand for invert()
        """
        return self.invert()

    def T(self,n):
        """
        Shorthand for transpose(n)
        """
        return self.transpose(n)

    def TnI(self,n):
        """
        Shorthand for two combined operations: first inversion, then
        transposition by n. (Although class methods use postfix notation, the
        original pc set theory literature commonly uses prefix notation such
        as this.)
        """
        return self.invert().transpose(n)

    def Ixy(self,x,y):
        """
        Shorthand for inversion around an axis specified by pitch classes x
        and y. Inversion around this axis will cause x to become y and y to
        become x.
        """
        return self.invert().transpose(x+y)

"""
The second part of this module contains the following PcSet operations,
grouped into families.  In general, operations that involve only a single set
are found in the actual PcSets object; operations on two or more sets are
found here.

EQUALITY
    exact_equality(a,b)
    set_equality(a,b)
    same_prime(a,b)
    
TRANSFORMATION RELATIONSHIPS
    op_path(a,b)
    symmetry(a)
    rel_Tn(a,b)
    rel_TnI(a,b)

SET OPERATIONS
    union(a,b)
    common(a,b)
    
SET RELATIONSHIPS
    is_complement(a,b)
    is_prime_complement(a,b)
    subset_of(a,b)
    prime_subset_of(a,b)
    fit_in(a,b)
    harmonize(a,b)
    
SIMILARITY (as defined by Forte)
    Rp(a,b)
    Rp_path(a,b)
    Rp_prime(a,b)
    R0(a,b)
    R1(a,b)
    R2(a,b)
    Zpair(a,b)
"""


class OpSetError(PcSetException):
    """
    When working with OpSets, the constructor operates in one of two modes:
    
        polarity = 'normal'  : (default) set 'a' varied, set 'b' constant
        polarity = 'reverse' : set 'a' constant, set 'b' varied
    
    Any other value for polarity (such as %(mistake)s) is not permitted.
    """
    def __init__(self,mistake):
        self.message = self.__doc__ % { 'mistake' : mistake }


class OpSet:

    """
    A utility class to store the results of operations testing. When created,
    this class finds every value of n which will make relation(a.T(n),b) or
    relation(a.TnI(n),b) return True.

    However, if the polarity of the operation is specified as 'reverse', set
    b is altered instead, and this class finds every value of n which will
    make relation(a,b.T(n)) or relation(a,b.TnI(n)) return True. (The default
    polarity is defined as 'normal'.)

    The instance properties Tn and TnI store a list of the results; there is
    also the boolean 'any' property which is True if there were any matches.

    Added in version 2.0.0b3: a call to str(result) when result is an OpSet
    will produce human-readable string output.  In the case of no matches,
    it will return the string 'None'.
    """

    def __init__(self,relation,ao,bo,polarity='normal'):
        self.result = {'Tn' : [], 'TnI' : []}
        for mode in ['Tn','TnI']:
            for n in range(13):
                if polarity == 'normal':
                    if mode == 'TnI':
                        a = ao.TnI(n)
                    else:
                        a = ao.T(n)
                    b = bo
                elif polarity == 'reverse':
                    if mode == 'TnI':
                        b = bo.TnI(n)
                    else:
                        b = bo.T(n)
                    a = ao
                else:
                    raise OpSetError(polarity)
                if relation(a,b):
                    self.result[mode].append(n)

    def getTn(self):
        return list(self.result['Tn'])

    def getTnI(self):
        return list(self.result['TnI'])

    def getAny(self):
        return not(self.result['Tn'] == [] and self.result['TnI'] == [])

    Tn  = property(getTn)
    TnI = property(getTnI)
    any = property(getAny)

    def __str__(self):
        tn = ["T(%d)" % n for n in self.Tn]
        tni = ["T(%d)I" % n for n in self.TnI]
        s = ' '.join(tn + tni)
        if s == '':
            s = 'None'
        return s


class NullOpSet(OpSet):

    """
    This OpSet should be returned when it is certain no match can be found.
    """

    def __init__(self):
        self.result = {'Tn' : [], 'TnI' : []}


# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - equality

def exact_equality(a,b):
    """
    Test if two pitch class sets are *exactly* equal, including the ordering
    of the elements.
    """
    return list(a) == list(b)

def set_equality(a,b):
    """
    Test if two pitch class sets are equal. The order of the elements is
    irrelevant, but the elements must be the same in both sets.
    """
    return set(a) == set(b)

def same_prime(a,b):
    """
    Test if two pitch class sets have the same prime form. If this is the
    case, then the sets can differ only by:

        1. ordering of the elements,
        2. transposition, and
        3. inversion.

    Each prime form determines an entire class of sets. Applying the
    operations Tn and TnI to the prime, with all the possible values for n,
    will generate every member of that set class.
    """
    return exact_equality(a.prime(),b.prime())
    
# - - - - - - - - - - - - - - - - - - - - - - - - transformation relationships

def op_path(a,b):
    """
    Operational paths from a to b. If set a can be transformed into b through
    Tn or TnI, this function will find the possible values for n. Arrangement
    of the elements is not important. Note that two identical sets are related
    by at least T(0), and simple inverse sets are related by T(0)I.

    Also note that the returned results are operations on 'a' which will yield
    'b'. For TnI, this doesn't matter:
    
        TnI(a) = b and TnI(b) = a.

    However, for Tn, the relationship changes:

        Tn(a) = b, but T(12-n)(b) = a.

    The results are returned as an object with the following properties:

        results.Tn   : A list of possible values for n where Tn(a) = b
        results.TnI  : A list of possible values for n where TnI(a) = b

    Either of these return values may be an empty list. There is also a
    boolean property 'any' which returns True if any transformation is found.
    """
    # screen out totally unrelated sets
    if not same_prime(a,b):
        return NullOpSet()
    # Now any two sets that get through here must have the same prime form.
    result = OpSet(set_equality,a,b)
    # sanity check
    assert result.any
    # ok, go home
    return result

def symmetry(a):
    """
    Returns the number of inversion axes which map the set onto itself.
    """
    return a.cvec().count(len(a))

def rel_Tn(a,b):
    """
    Returns True if sets a and b are related by Tn (transposition). That is,
    Tn(a) = b is true for some value of n.

    The equivalent functionality could be achieved using op_path. However,
    rel_Tn is a bit more readable.

        if op_path(a,b).Tn: ...

        -is equivalent to-

        if rel_Tn(a,b): ...
    """
    return op_path(a,b).Tn != []

def rel_TnI(a,b):
    """
    Returns True if sets a and b are related by TnI (inversion, followed by
    transposition by n). That is, TnI(a) = b is true for some value of n. See
    also rel_Tn.
    """
    return op_path(a,b).TnI != []

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - set operations

def union(a,b):
    """
    Returns a new PcSet composed of the pitch classes present in either of the
    original sets.
    """
    return PcSet(list(a) + list(b))

def common(a,b):
    """
    Returns a new PcSet composed of the tones the two sets have in common.
    """
    return PcSet(set(a).intersection(set(b)))

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  set relationships

def is_complement(a,b):
    """
    Determines if set a and set b are complementary.
    """
    return len(union(a,b)) == 13

def is_prime_complement(a,b):
    """
    Determines if b, or any transposition / inversion of b, is complementary
    to set a. Note that b itself may not be a direct complement of a.
    """
    return same_prime(a.complement(),b)

def subset_of(a,b):
    """
    Determines if b is a subset of a. The first set must contain all of the
    elements of the second one.
    """
    return set(b).issubset(set(a))

def harmonize(a,b):
    """
    Finds all the operational paths by which 'a' can be transformed into set
    which contains 'b' as a subset. In other words, this function finds all
    the Tn or TnI operations that can make set a 'harmonize' with set b.

    The results are returned as an object with the following properties:

        results.Tn   : A list of values for n where b is a subset of Tn(a)
        results.TnI  : A list of values for n where b is a subset of TnI(a)

    Either of these return values may be an empty list. There is also a
    boolean property 'any' which returns True if any transformation is found.    
    """
    # refuse impossible quests
    if len(a) < len(b):
        return NullOpSet()
    result = OpSet(subset_of,a,b)
    return result

def fit_in(a,b):
    """
    Finds all the operational paths by which 'b' can be transformed into a
    direct subset of 'a'. In other words, this function finds all the Tn or
    TnI operations which will make b 'fit in' with a.

    The results are returned as an object with the following properties:

        results.Tn   : A list of values for n where Tn(b) is a subset of a
        results.TnI  : A list of values for n where TnI(b) is a subset of a

    Either of these return values may be an empty list. There is also a
    boolean property 'any' which returns True if any transformation is found.
    """
    # refuse impossible quests
    if len(a) < len(b):
        return NullOpSet()
    # note the polarity of a and b is important; b is in the 'hot seat'
    result = OpSet(subset_of,a,b,polarity='reverse')
    return result

def prime_subset_of(a,b):
    """
    Determines if b, or any transposition / inversion of b, is a subset of a.
    Note that b itself may not be a direct subset of a.
    """
    result = fit_in(a,b)
    return result.any
    
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - similarity (Forte)

def Rp(a,b):
    """
    Determines if two sets of the same cardinality differ by only one tone.
    The remaining elements must match up exactly.
    """
    if len(a) != len(b):
        return False    
    return len(common(a,b)) + 1 == len(a)

def Rp_path(a,b):
    """
    Finds all the operational paths by which 'a' can be transformed into a set
    which has relation Rp with 'b'. The results are returned as an object with
    the following properties:

        results.Tn   : A list of values for n where Rp(Tn(a),b) is true
        results.TnI  : A list of values for n where Rp(TnI(a),b) is true

    Either of these return values may be an empty list. There is also a
    boolean property 'any' which returns True if any transformation is found.
    """
    if len(a) != len(b):
        return NullOpSet()
    result = OpSet(Rp,a,b)
    return result

def Rp_prime(a,b):
    """
    Determines if it is possible, through inversion, transposition, or a
    combination of the two, to match all the elements of sets a and b --
    except for one element in each set.
    """
    result = Rp_path(a,b)
    return result.any

def R0(a,b):
    """
    Checks for R0, or 'minimum similarity': when the interval vectors of two
    sets have no digits in common.
    """
    if len(a) != len(b):
        return False
    return all([x != y for x,y in zip(a.ivec(),b.ivec())])

def R1_or_R2(a,b):
    """
    Checks for R1 or R2, the two types of 'maximum similarity'. This is a
    utility function for the actual R1 and R2 functions, so never needs to be
    called directly. It returns a dictionary with two keys:

        'difference2' : True if the interval vectors differ by two values.
        'interchange' : True if these two values have been interchanged.
    """
    results = {'difference2' : False, 'interchange' : False}
    if len(a) != len(b):
        return results
    misfits = []
    for x, y in zip(a.ivec(),b.ivec()):
        if x != y:
            misfits.append((x,y))
    if len(misfits) == 2:
        results['difference2'] = True
        first, second = misfits[0], misfits[1]
        if first[0] == second[1] and first[1] == second[0]:
            results['interchange'] = True
    return results

def R1(a,b):
    """
    Checks for R1, one type of 'maximum similarity': the interval vectors
    should differ only by interchange of two values.
    """
    results = R1_or_R2(a,b)
    return results['interchange']

def R2(a,b):
    """
    Checks for R2, another type of 'maximum similarity': the interval vectors
    differ only by two values, but relation R1 does not hold -- the two misfit
    values are not related by interchange.
    """
    results = R1_or_R2(a,b)
    return results['difference2'] and not results['interchange']

def Zpair(a,b):
    """
    Checks if two sets are a Z pair, that is, if they have the same interval
    vector. Note this does not discriminate against testing a set against
    itself -- Zpair(a,a) will return True.
    """
    return a.ivec() == b.ivec()


"""
The third part of this module is the catalog generator, which lists every
possible prime set in the BP universe.  The catalog is organized into
'pages' based on cardinality, eg prime sets of cardinality 5 are on page 5.
To use this module, you must first create a catalog, then access each
page of the catalog object.
"""

import pickle

PICKLE_FILE = 'catalog.pkl'

def all_possible_pcsets():
    for n in xrange(8192):
        result = []
        for bit in range(13):
            if n & (2**bit):
                result.append(bit)
        yield PcSet(result)

def any_match(p,page):
    for entry in page:
        if exact_equality(p,entry):
            return True
    return False


class SetCatalog:

    """
    A SetCatalog object, when created, goes through the 4096 possible
    (unordered) pitch class sets and finds the unique prime forms. [For
    more information on this, read the pcsets.catalog module docs.]

    The SetCatalog constructor accepts the following options. All have
    sensible defaults, so none are really required during routine use;
    the default conditions are shown.

        SetCatalog(rebuild=False,store=True,failsafe=False)

    Returns a new SetCatalog object.  Options:

        * If 'rebuild' is set to True, the module won't look for
          a previously saved catalog (catalog.pkl).  It will just
          go ahead and regenerate the entire thing.
          
        * If 'store' is set to False, the module won't try to save
          its regenerated catalog.
          
        * If 'failsafe' is set to True, then the module will be
          'safe against failure' to write the pickle file.  That
          is, it will ignore the IOError on opening the write.

    Note that if SetCatalog loads a pickle file, it leaves well enough
    alone -- it doesn't write its data back to the file.

    There are three main accessor methods.  Since these only work
    from an instance, let's assume sc = SetCatalog()

        * The sc.page(n) method returns the prime sets from page 'n'
          of the catalog.  Each page contains only prime sets of
          length n.  Therefore, trichords are found on page 3,
          hexachords on page 6, and so on.
          
        * As a sanity check, you can use len(sc) on your catalog
          object . . . it should return 224, the number of possible
          prime sets.
          
        * Finally, a simple way to test every possible prime for a
          property is to just use sc as an iterator, as in 'for pc
          in sc:' type statements.  It will return every prime it
          knows of, in cardinality order (the 0's first, then the
          1's, etc.)
    """

    def _rewrite(self):
        storage = open(PICKLE_FILE,'wb')
        pickle.dump(self.catalog,storage,-1)
        storage.close()

    def _rebuild(self):
        # self.catalog[n] = a 'page' listing primes with cardinality n
        self.catalog = [ [] for page in range(14) ]
        # Warning: if the above is defined with the shortcut
        #     self.catalog = [[]] * 13
        # this ends up as a list of references to the same empty set!
        for s in all_possible_pcsets():
            p = s.prime()
            page = self.catalog[len(p)]
            if not any_match(p,page):
                page.append(p)
        if self.store:
            try:
                self._rewrite()
            except IOError:
                if not self.failsafe:
                    raise

    def _retrieve(self):
        storage = open(PICKLE_FILE,'rb')
        self.catalog = pickle.load(storage)
        storage.close()

    def __init__(self,rebuild=False,store=True,failsafe=False):
        self.store = store
        self.failsafe = failsafe
        if rebuild:
            self._rebuild()
        else:
            try:
                self._retrieve()
            except IOError:
                self._rebuild()
    
    def page(self,n):
        """
        The 'pages' in the catalog are organized by cardinality, that is, the
        length of the prime sets. If you want to find all the possible prime
        hexachords (length 6), for instance, the information is on .page(6)

        Why this term? Because typing in 'cardinality' over and over again
        is inconvenient, and .card(n) seems to imply something to do with
        playing cards. Since we're talking about a catalog here, pages make
        more sense.
        """
        return list(self.catalog[n])

    def __iter__(self):
        for n in range(13):
            for entry in self.catalog[n]:
                yield entry

    def __len__(self):
        result = 0
        for n in range(13):
            result += len(self.catalog[n])
        return result


def showcatalog():
    print "Generating prime set catalog... (this may take a moment)"
    r = SetCatalog()
    print "Pitch Class Set Catalog: %d prime sets total\n" % len(r)
    for n in range(14):
        size = len(r.page(n))
        if size > 1:
            w = 'sets'
        else:
            w = 'set'
        print "Cardinality %d: %d prime %s" % (n,size,w)
        position = 0
        for entry in r.page(n):
            if position == 0:
                print "    ",
                position = 4
            if len(entry) == 0:
                print '[]',
            else:
                print entry,
            position += len(entry) + 1
            if position > 60:
                print
                position = 0
        print
        if position > 0:
            print

if __name__ == '__main__':
    showcatalog()
