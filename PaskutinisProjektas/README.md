# Filmų katalogavimo sistema

## Projekto tikslas

Sukurti C++ konsolinę programą, kuri leidžia valdyti filmų katalogą: peržiūrėti filmus, pridėti naujus filmus, redaguoti, pašalinti, ieškoti.

## Pasirinktos temos aprašymas

Pasirinkta tema – filmų katalogas. Programa skirta saugoti informaciją apie filmus. Kiekvienas filmas turi pavadinimą, režisierių, išleidimo metus, žanrą ir įvertinimą.

## Programos funkcionalumas

Programa leidžia atlikti šiuos veiksmus:

1. Rodyti visus filmus.
2. Pridėti naują filmą.
3. Redaguoti esamą filmą.
4. Pašalinti filmą.
5. Ieškoti filmo pagal pavadinimą.
6. Rikiuoti filmus pagal metus.
7. Apskaičiuoti vidutinį filmų įvertinimą.
8. Sukurti ataskaitą tekstiniame faile.

## CRUD funkcionalumas

Programa įgyvendina visas CRUD operacijas:

- Create – naujo filmo pridėjimas;
- Read – filmų peržiūra;
- Update – filmo redagavimas;
- Delete – filmo pašalinimas.

## Naudojami failai

- `main.cpp` – pagrindinis programos kodas.
- `filmai.txt` – pradinių ir atnaujintų duomenų failas.
- `ataskaita.txt` – programos sugeneruota filmų ataskaita.

## Duomenų failo formatas

Duomenys faile `filmai.txt` saugomi tokiu formatu:

Pavadinimas;Režisierius;Metai;Žanras;Įvertinimas
