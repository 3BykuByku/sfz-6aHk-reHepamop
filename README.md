
# Генератор multi-layered sfz из папки семплов

- предварительно семплы нужно сгруппировать по папкам (названия папок см. 1 колонку файла GM.csv)

- слой (диапазон velocity для multi-layer) назначается по сортировке по имени файла

- семплы на слой группируются по числу в названии файла

- если семплов на слой больше 1-го - прописывает настройки для поочередного их проигрывания (пример названия - nameA-01.wav / name01-01.wav ... nameZ-01.wav / name10-01.wav)

## Установить зависимости

`pip2 install scandir`

## Обновление GM.py из GM.csv

`python2 update-gm-drums.py`

## Создание файла generated.sfz в папке с семплами

`python2 drumkit.py "path/to/your-samples-kit`

## Генератор sfz по меткам

`python2 slices.py "path/to/loops/файл-меток.txt" [частота дискретизации]`

для меток "битов" (левая граница = правая граница)

`python2 slices.go "path/to/loops/файл-меток.txt" [частота дискретизации]`

для меток "регионов"

`python2 slices.go "path/to/loops/файл-меток.txt" [частота дискретизации] 1`

- предварительно создать файл меток в Audacity -> Analyze -> Beat Finder или вручную
- название файла меток = название звукового файла = название sfz файла

## TODO

- slices.go - переделать на js - драг-н-дропом кидается файл - парсятся метки - генерится sfz c сылкой на скачивание (или возможность сохраниния файла в той же папке)
+ посмотреть визуальное представление аудио - нарезание меток вручную в браузере.
- ?автоматизировать создание файлов с метками по аудио-файлу

- утилита для правки путей lmms проекта

- генератор на основе формата lmms

- ?переписать на perl
