# FORR3CG - Lokaverkefni
Viktor Óli Bjarkason - Tækniskólinn - 2023

## Skýrsla

[Dagbók](https://github.com/viktorob/FORR3CG_lokaverkefni/dabgok.md)

Í þessu verkefni áttum við að skrifa forrit sem heldur utan um búnað Tækniskólans og staðsetningu hans. Þetta gerði ég með því að skrifa listaklasa sem hélt utan um undirklasa sem erfa parent klasa og skrifa síðan notendaviðmót sem vinnur með listann. Ég valdi að nota tætitöflu (hash table) sem listaklasann þar sem það veitir flest stig og ætti að vera aðeins meiri áskorun. Mín útfærsla virkar þannig að nánast öll virkni er útfærð í föllum í klösunum og því þurfti ég nánast bara að kalla á þau í notendaviðmótinu sama hvað þurfti að gera.

### Aukakröfur

- Skráavinnsla, hægt er að skrifa listann í skrár og lesa í listann úr skrá. (10 stig)
- Gögnin eru röðuð í listanum (eftir verðmæti). Útheimtir að útfæra samanburðarvirkjana. (5 stig)
- Litir í viðmóti (skipanir eru bláar, villur rauðar og gögn gul) (5 stig)
- Prenta á skjá búnað í ákveðinni stofu og ákveðinni hæð í ákveðnu húsi. (5 stig)
- Prenta á skjá búnað af ákveðinni gerð, t.d. alla stóla. (gerði fyrir allar gerðir) (5 stig)
- Afritunarsmiður (e. copy constructor) og gildisveitingavirkinn (e. assignment operator) fyrir listaklasann. (5 stig

_Annað sem mér datt í hug (og útfærði auðvitað)_
- Prenta gögn úr skránni (án þess að yfirskrifa núverandi gögn)

### Leiðbeiningar fyrir viðmót

#### Skýringar

TÝPA = borð, stóll, skjávarpi og tölva

AUKA = sætafjöldi, snúningur, lúmen, kaupár

ATH. SKRÁARHEITI gerir ráð fyrir að skráin sé .txt (ekki þarf að taka það fram) og er valkvæmt, ef ekkert er valið er gogn.txt lesin.

#### Skipanir

SKRÁ búnað
```
skrá {TÝPA} {auðkenni} {stadsetning} {verðmæti} {AUKA}
Dæmi: skrá borð 501 21209 1000 4
```

EYÐA búnaði
```
eyða {auðkenni}
Dæmi: eyða 501
```

UPPFÆRA staðsetningu búnaðar
```
uppfæra {auðkenni} {ný staðsetning}
Dæmi: uppfæra 501 23250
```

PRENTA búnað eftir auðkenni
```
prenta id {auðkenni}
Dæmi: prenta 501
```

PRENTA búnað eftir húsi
```
prenta hús {HÚS}
Dæmi: prenta hús 09
```

PRENTA búnað eftir týpu
```
prenta {TÝPA}
Dæmi: prenta stóla
```

PRENTA búnað eftir nákvæmri staðsetningu (húsi, hæð og herbergi)
```
prenta stað {HÚS} {HÆÐ} {HERBERGI}
Dæmi: prenta stað 21 2 9
```

PRENTA GÖGN úr skrá
```
prenta skrá {SKRÁARHEITI} eða prenta skrá
Dæmi: prenta skrá flottskra
```

LESA gögn úr skrá (og yfirskrifa núverandi)
```
lesa {SKRÁARHEITI} EÐA lesa
Dæmi: lesa flottskra
```

### Myndband

[Myndband með virkni](https://drive.google.com/file/d/1N1EQrB2wpwxePuDP8BIsrab_TgQ_4MHA/view?usp=sharing)