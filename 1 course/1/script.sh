#! /bin/bash

cd /home/kristiannikulin/'Рабочий стол'

pwd

# Создадим переменную с командой ls
info=` ls -a`
echo Detailed information:
echo $info

echo Текст в файле один > file1.txt
echo Текст в файле два > file2.txt

# Первый текст теперь в file3
cat file1.txt > file3.txt

# Добавляем второй текст к первому
cat file2.txt >> file3.txt

rm file2.txt

mkdir folder

# Перемещаем file3 в папку
mv file3.txt ./folder/
# Копируем file1 в папку
cp file1.txt ./folder/

# Ищем file3 после перемещения
find -name file3

cd /dev
# Создаем "закладку" в папке dev
pushd .
cd /home/kristiannikulin/'Рабочий стол'

#Теперь мы можем к ней вернутся
popd
cd -

# Ищем файл в названии которого есть 3
cd folder
ls | grep 3

# Найдем все файлы в текущей директории с разрешением .txt и удалим их
#find . -name '*.txt' | xargs rm