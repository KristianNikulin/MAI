#!/bin/bash

quote=$'\042'
# find . -maxdepth 1 -name "*$suffix" -type f -atime "+$days" -exec rm -i {} \;

function Help()
{
    echo "Программа удаляет в текущем каталоге файлы с указанным суффиксом,"
    echo "к которым не было обращения указанное количество дней."
    echo
    echo "Usage: <путь к каталогу> <суффикс> <кол-во дней>"
    echo "For example: "/home/kristiannikulin/$quoteРабочий стол$quote" "$quote.txt$quote" "2"";
}

while getopts ":h" option; do
    case $option in
	h) # Help
        Help
        exit;;
    \?) # wrong \? *
        echo "Неправильный параметр"
        exit;;
    esac
done

dir="$1"
suffix="$2"
days="$3"
find "$dir" -name "*$suffix" -type f -atime "$days" -exec rm -i {} \; # можно убрать -i и тогда они будут удаляться сразу без разрешения
