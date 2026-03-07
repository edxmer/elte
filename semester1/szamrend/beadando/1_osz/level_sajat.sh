#!/bin/sh



# $1: sablon elérési útja
# $2: adatbázis elérési útja

# Bemenet hibaellenőrzése


if test $# -lt 2; then
    echo "Nem adtál meg elég paramétert."
    exit 1
fi

if test ! -f "$1"; then
   echo "A sablon elérési útja nem jó."
   exit 2
fi

if test ! -f "$2"; then
   echo "Az adatbázis elérési útja nem jó."
   exit 3
fi

# Feldolgozás

szoveg=`cat $1`
adatok=`cat $2`

hossz=`echo "$adatok" | wc -l`
for i in `seq $hossz`; do

#echo $i
sor="`echo \"$adatok\" | head -n $i | tail -n 1`"
#echo $sor

nev="`echo $sor | grep -oh -E '^[^;]*'`"
cim="`echo $sor | grep -oh -E ';[^;]*;' | sed 's/^.//' | sed 's/.$//'`"
idopont="`echo $sor | grep -oh -E '[^;]*$'`"


level="`echo \"$szoveg\" | sed \"s/<nev>/$nev/g\" | sed \"s/<cim>/$cim/g\" | sed \"s/<idopont>/$idopont/g\"`"

echo "\n------ $i. levél ------\n"
echo "$level"

done



echo -n "\n---------------------"
echo `echo $hossz | sed 's/[0-9]/-/g'`
