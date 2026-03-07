#!/bin/sh
# Használat: ./korlevel.sh korlevel_sablon.txt adatbazis.txt

if [ $# -ne 2 ]; then
    echo "Használat: $0 sablon_fajl adatbazis_fajl" >&2
    exit 1
fi

SABLON="$1"
ADATBAZIS="$2"

if [ ! -f "$SABLON" ]; then
    echo "Hiba: A sablon fájl nem létezik: $SABLON" >&2
    exit 2
fi

if [ ! -f "$ADATBAZIS" ]; then
    echo "Hiba: Az adatbázis fájl nem létezik: $ADATBAZIS" >&2
    exit 3
fi

# Olvassuk soronként az adatbázist
while IFS=";" read -r nev cim idopont || [ -n "$nev" ]; do
    # Üres sorokat átugrunk
    [ -z "$nev" ] && continue

    # Helyettesítés: <nev>, <cim>, <idopont>
    sed \
        -e "s/<nev>/$nev/g" \
        -e "s/<cim>/$cim/g" \
        -e "s/<idopont>/$idopont/g" \
        "$SABLON"
    echo "---------------------------------------------"
done < "$ADATBAZIS"

