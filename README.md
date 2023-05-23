# MobileMeshNetworkSimulator
A Mobile Mesh Network Simulator

Never finished it. Had to prioritize other stuff.....

## Nettverk
- **Type nettverk:** Mobile Mesh Network
    - Selvorganiserende nettverk
    - Noder bør kunne koble seg til og fra nettverket
- **Størrelse:** 
    - Usikker
- **Topologi:** 
    - Usikker
## Node
- **Mobilitet:** 
    - Noder bør kunne bevege seg rundt i nettverket
    - Må definere en mobilitetsmodell som beskriver hvordan nodene beveger seg
- **Kommunikasjon:**
    - Noder bør kunne kommunisere med hverandre
    - Noder bør kunne sende meldinger til hverandre
    - Skal nodene ha en begrenset rekkevidde? Og kanskje sende meldinger via andre noder?

## Interaksjoner
- **Kommunikasjonsprotoller:** 
    - Må definere en protokoll for hvordan nodene skal kommunisere med hverandre
    - Routingprotokoller 

## Performance metrics
- **Throughput:** 
    - Hvor mange meldinger kan sendes per tidsenhet?
- **Latency:** 
    - Hvor lang tid tar det for en melding å komme frem?
- **Pakketap:** 
    - Hvor mange pakker blir mistet i nettverket?
- **Energiforbruk:**
    - Hvor mye energi bruker nodene på å sende meldinger?
    - Hvor mye energi bruker nodene på å motta meldinger?
    - Hvor mye energi bruker nodene på å være i nettverket?
    - Hvor mye energi bruker nodene på å være i søvnemodus?

## Noder
Representerer en node i nettverket, og bør ha følgende egenskaper:
posisjon, mobilitet, energi, rekkevidde, naboer, meldinger, etc.

## Meldinger
Representerer en melding som sendes mellom noder, og bør ha følgende egenskaper:
avsender, mottaker, innhold, etc.

## Nettverk
Representerer et nettverk av noder, og bør ha følgende egenskaper:
alle noder i nettverket, legge til og fjerne noder, oppdatering av tilstand i nettverket

## Routing
Siden mulige motivasjoner i oppgavebeskrivelsen var slik:

- Redningsaksjoner i ulendt terreng
- Kartlegging av utrygge områder
- Sikre posisjonen til operatør mot triangulering

Bør en protokoll som kan håndtere dynamiske og hurtig endrende nettverkstopologier være passende.
- En slik protokoll kan være AODV (Ad hoc On-Demand Distance Vector Routing Protocol)
- En slik protokoll kan være DSR (Dynamic Source Routing Protocol)

### Implementasjon av AODV
- [ ] **Implementer route requests (RREQ):**
   - Når en node trenger å sende en melding til en destinasjon og den ikke har en rute, skal den broadcaste en route request (RREQ) melding.
   - RREQ-meldingen skal inneholde kilde nodens ID, destinasjons nodens ID, og en broadcast ID som økes for hver RREQ kildenoden sender.

- [ ] **Implementer route replies (RREP):**
   - Når en node mottar en RREQ, skal den sjekke om den er destinasjonen, eller om den har en god nok rute til destinasjonen.
   - Hvis den gjør det, skal den sende et route reply (RREP) tilbake til kildenoden.
   - Hvis den ikke gjør det, skal den øke hop count i RREQ og broadcaste den til sine naboer.

- [ ] **Implementer rouste maintenance:**
   - Hvis en node oppdager et lenkebrudd mens den videresender en pakke, skal den sende en rute feil (RERR) melding til kildenoden.
   - Når kilde noden mottar RERR, skal den fjerne den ødelagte ruten fra rutingtabellen.
   - Hvis den fortsatt trenger å sende pakker til destinasjonen, kan den starte ruteoppdagelse på nytt.

## todos
- [x] Implement a basic Node class
- [x] Implement a basic Network class
- [x] Implement a basic Message class
- [x] Create a basic prototype of the simulator
- [ ] Implement a routing algorithm
- [ ] Implement performance metrics in the Network class
