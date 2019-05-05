<?php

namespace SfzTools;

//const ID = "hello.world";
define(__NAMESPACE__ . "\ID", "hello.world");

echo "ID = " . ID;
echo "\n";

var_dump(
	"Script arguments:",
	$argc,
	$argv,
	__FILE__
	//,$_SERVER,
);
echo "\n";

$content = file_get_contents("global.json"); //__FILE__
echo "\nContent: " . $content . "\n";

file_put_contents("test-new-file.tmp", '
	Here
	new
	content...
');


var_dump(
	//function_exists("phpinfo"),
	dirname(__FILE__)
);

foreach (scandir(dirname(__FILE__)) as $f) {
	echo $f . "\n";
}
