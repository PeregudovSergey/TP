#!/bin/bash

declare -A ms
ms[$1]=$2
ms[$3]=$4
ms[$5]=$6
ms[$7]=$8

folder=${ms["--input_folder"]}
extension=${ms["--extension"]}
backup_folder=${ms["--backup_folder"]}
archive_name=${ms["--backup_archive_name"]}
	
mkdir $backup_folder

find $folder -name "*.$extension" > "$backup_folder/files"

pt=0

while IFS= read -r line
do
   	touch "$backup_folder/$pt.$extension"	
   	cat "$line" > "$backup_folder/$pt.$extension" 
   	let "pt += 1"
   	#echo "$line"  	
done < "$backup_folder/files"

rm "$backup_folder/files"

tar -czf "$archive_name" "$backup_folder"

echo done