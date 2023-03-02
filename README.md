# DIY Delay-Effektgerät mit dem Teensy 4.1 – Kurzanleitung

XXX

<a name="toc"></a>
## Table of Contents

> 1. [Introduction](#introduction)
> 2. [Components](#components)
> 3. [Implementation](#implementation)

<a name="introduction"></a>
## 1. Introduction

XXX

#### If your project already has a style guide, you should follow it.
If you are working on a project or with a team that has a pre-existing style guide, it should be respected.  Any inconsistency between an existing style guide and this guide should defer to the existing.

Einleitung
Im Rahmen einer Projektarbeit wurde im Wintersemester 2022/23 ein digitales Delay-Effektgerät entwickelt. Es wurden dafür ein Teensy-Microcontroller zusammen mit einfachen Bauteilen verwendet. Dank des simplen Aufbaus und der unkomplizierten Programmierung des Teensy kann dieses Projekt als Vorlage für weitere Audio-Effektgeräte dienen. Dazu wird in dieser Kurzanleitung die Umsetzung eines solchen Audio-Effektgeräts beschrieben und was dafür erforderlich ist.
Davor aber noch eine kurze Beschreibung des entwickelten Effekts: Es handelt sich um einen simplen Delay-Effekt, der getrennt auf den linken und rechten Audiokanal angewendet wird. Als Effekt-Parameter lassen sich steuern:
•	Delay Time (links/rechts)
•	Feedback Decay (links/rechts)
•	Color (links/rechts)
•	Modulation (links/rechts)
Des Weiteren verfügt das Effektgerät über die folgenden Einstellungen:
•	On/Off (Bypass)
•	Input Volume
•	Output Volume
•	Dry/Wet
•	BPM
Material
Zunächst soll das verwendete Material aufgelistet werden. Für Abwandelungen des Projekts kommen ggf. andere Bauteile in Frage.
Grund-Bauteile
•	1 x Teensy 4.1
•	1 x Teensy Audio Shield Rev D
•	2/4 x Klinkenstecker (Mono/Stereo)
•	3 x Dreh-Encoder (begrenzt)
•	1 x Fußschalter
Delay Effekt
•	1 x LED-Display
•	5 x Dreh-Encoder (endlos, schrittweise, mit Push-In-Button)
•	Stiftleisten
•	Buchsenleisten
•	Drahtkabel isoliert
•	Gehäuse
PCB
•	1 x individuell angefertigte PCB 
•	Buchsengehäuse 3- & 5-Pin
•	Stiftleiste 3- & 5-Pin
•	extra Buchsenleisten
•	4 x Klinkenstecker für PCB-Bohrung (Stereo)
Umsetzung
Sind alle Materialien vorhanden, kann das Projekt technisch umgesetzt werden.
Hardware
Bei der Hardware-Umsetzung geht es zunächst darum, wie die Parameter des Effektes gesteuert werden sollen. Neben den essenziell benötigten Dreh-Encodern für Dry/Wet und Volume In und Volume Out setzten wir ein Fußschalter für Bypass als Basis voraus. Diese Basis dient als Grundlage für jeden Effekt. Bei einem Delay-Effekt werden in der Regel weitere Dreh-Encoder für Delay Time und Feedback Decay benötigt. Je nach Bedarf können weitere Funktionen dem Pedal hinzugefügt werden (weitere Funktionen, LEDs, Display, etc.).
Erste Schritte
1.	Gedanken darüber machen, welche und wie viele Steuerelemente für den Effekt genutzt werden sollen
2.	Schaltplan erstellen
3.	Breadboard-Aufbau mit Grund-Bauteilen
4.	Grundfunktionstest
5.	Erweiterte Funktionen am Breadboard testen
6.	Finaler Funktionstest am Breadboard mit allen Komponenten 
7.	Weiter mit PCB-Design / DIY Löten der Komponenten 
PCB
1.	Online PCB Design Tool auswählen, zum Beispiel EasyEDA
2.	Breadboard Schaltplan digitalisieren
3.	PCB gestalten
4.	Überprüfen des Schaltplans und der PCB
5.	Gerber-Datei exportieren
6.	PCB-Bestellung via PCBway oder einem anderen Anbieter
7.	PCB mit Klinkenstecker, Buchsenleisten und Stiftleisten bestücken (je nach Bedarf und Design der PCB)
8.	Dreh-Encoder und weitere Steuerelemente verkabeln inklusive Stiftleisten
9.	PCB mit den Grundbauteilen verbinden und Funktionalität testen
 
Abbildung 1: PCB-Design

 
Abbildung 2: PCB mit Bauteilen bestückt
Gehäuse
1.	Gehäuse vorbereiten (Bohrungen und Aussparungen für Encoder, etc.)
2.	Hardware in das Gehäuse verbauen.
 
Abbildung 3: Benutzeroberfläche des Gehäuses
Software
Ist die Hardware erfolgreich angeschlossen, muss noch ein entsprechendes Skript auf den Teensy geladen werden. Dazu sind folgende Schritte notwendig:
1.	Die Arduino IDE installieren
2.	In der Arduino IDE die Teensyduino-Erweiterung installieren
3.	Den Teensy über ein USB-Kabel am PC anschließen
4.	In der Arduino DIE:
a.	Das korrekte Board auswählen (Werkzeuge/Board/Teensyduino/…)
b.	Den korrekten USB-Port auswählen (Werkzeuge/Port/…)
c.	Den Code löschen und das verwendetet Skript einfügen
Delay-Skript
Für das Projekt wurde folgendes Skript verwendet:
https://github.com/PaulToast/Teensy-Delay-Pedal/blob/main/DelayScript.ino
Eigenes Skript erstellen
Für die Erstellung eines eigenen Skripts wird die Verwendung des Audio System Design Tool for Teensy Audio Library empfohlen. Über das visuelle Interface können Signalwege konfiguriert werden und als Teensyduino Code exportiert werden. Falls Bedienelemente verwendet werden (Dreh-Encoder, etc.), müssen diese anschließend noch im Skript implementiert werden.
