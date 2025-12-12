# Gebruiksaanwijzing

### opladen / vervangen batterijen
Vervang de batterijen indien ze leeg zijn van type 18650, de batterijhouder bevind zich op de achterkant van de linefollower.

### draadloze communicatie
#### verbinding maken
Download eerst de "Serial Bluetooth Terminal" app. Of een andere geschikte app, ik koos voor deze aangezien er macros ingesteld kunnen worden die het debuggen makkelijk maken. Steek de batterijen in de wagen en zet de bluetooth van je smartphone aan en maak verbinding met HC-05, de code is meestal 0000 of 1234 (In mijn geval 1234). Open de bluetooth serial terminal app en druk op het stekker icoontje rechtsboven.

#### commando's
debug [on/off]  
start  
stop  
set cycle [µs]  
set power [0..255]  
set diff [0..1]  
set kp [0..]  
set ki [0..]  
set kd [0..]  
set dAlpha [0..1]  
calibrate black  
calibrate white  

### kalibratie
Zet de wagen op een volledig zwart oppervlak en stuur het commando "calibrate black". Zet daarna de wagen op een compleet wit oppervlak en stuur het commando "calibrate white". 

### settings
De robot rijdt stabiel met volgende parameters:
Cycle time: 2500, Power: 190, diff: 0.45, kp: 14, ki: 0.03, kd: 0.3, dAlpha: 0.7

### start/stop button
De run on en off heb ik geimplementeerd in een macro op de bluetooth serial monitor app, heel simpel in te stellen door te houden op een vrije knop en het commando (run on/off) te schrijven. Ook heb ik dit gedaan voor het commando debug, heel handig voor rap de waardes te zien. De linefollower stopt vanzelf als die geen duidelijke zwarte lijn ziet.
