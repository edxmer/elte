#!/bin/sh

if test $# -eq 3; then

 # 1. első paraméter faktoriálisa
 fakt=1
 i=$1
 while test $i -gt 1; do
  i=`expr $fakt \* $i`
  i=`expr $i - 1`
 done

 echo "$1 faktorialisa: $fakt"

 # 2. cp

 if cp "$2" "$3" 1>/dev/null 2>&1; then
  echo "$2 sikeresen átmásolva $3 helyre"
 else echo "Nem sikerült $2 átmásolása $3 helyre"; fi


 # 3. a és b
 echo -n "a: "; read a
 echo -n "b: "; read b

 tailcount=`expr $b - $a + 1`


 kallsyms="`cat /proc/kallsyms | head -n $b | tail -n $tailcount`"

 if test "$kallsyms" = ""; then
  echo "Üres a kiírni kívánt string, nem jó az a és b érték amit írtál"
 else echo "$kallsyms"; fi


 # 4. command
 while echo -n "> "; read command; test "$command" != "kilépés"; do
  if test "$command" = "dátum"; then
   echo `date`
  elif test "$command" = "belép"; then
   echo "`who`"
  elif test "$command" = "összead"; then
   echo -n "x: "; read x
   echo -n "y: "; read y
   echo "$x + $y = `expr $x + $y`"
  fi
 done

else echo 'Nem 3 paramétert adtál meg.'; fi
