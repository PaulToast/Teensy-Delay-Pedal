# DIY Delay Effect Pedal using the Teensy 4.1

This article details the implementation of a DIY audio effect pedal and provides a step-by-step guide.

<a name="toc"></a>
## Table of Contents

> 1. [Introduction](#introduction)
> 2. [Components](#components)
> 3. [Implementation](#implementation)

<a name="introduction"></a>
## 1. Introduction

### Sections
> 1.1 [Project](#project-description)

> 1.2 [Delay Effect](#delay-description)

<a name="project-description"></a>
### 1.1 Project

As part of a university project at the [HAW Hamburg](https://www.haw-hamburg.de/), a delay effect pedal for use in music production was developed using the [Teensy 4.1](https://www.pjrc.com/teensy/) micro-controller, as well as other basic components. Because of the simple setup, it can easily be adjusted for different audio effects. The following guide provides an example that can be modified for different needs.

XXX describe different article contents and how to use

<a name="delay-description"></a>
### 1.2 Delay Effect

The audio effect that was chosen for the project is a simple delay effect with separate delay blocks for the left and right channel. The following effect parameters are seperately adjustable:
- Delay Time
- Feedback Decay
- Color
- Modulation

Additionally, the following controls are implemented:
- On/Off (Bypass)
- Input Volume
- Output Volume
- Dry/Wet
- BPM

**[Back to Top](#toc)**

<a name="components"></a>
## 2. Hardware Components

### Sections
> 2.1 [Base Components](#base-components)

> 2.2 [Delay Effect Components](#delay-components)

> 2.3 [Additional Components](#additional-components)

<a name="base-components"></a>
### 2.1 Base Components

Base Components that are needed to create the foundational input / output and audio processing:
| Amount    | Component                     |
| --------- | ----------------------------- |
| 1         | [Teensy 4.1](https://www.pjrc.com/store/teensy41.html) |
| 1         | [Teensy Audio Shield Rev D](https://www.pjrc.com/store/teensy3_audio.html) |
| 2/4       | 6,3mm TRS Jack (mono/stereo)  |
| 3         | Rotary Encoder (limited)      |
| 1         | Footswitch                    |

<a name="delay-components"></a>
### 2.2 Delay Effect Components

Components for parameter control of the specific Delay Effect:
| Amount    | Component                     |
| --------- | ----------------------------- |
| 1         | [Display](https://www.pjrc.com/store/display_ili9341_touch.html) |
| 5         | Rotary Encoder (endless, stepped, with push-in-button) |

<a name="baadditionalse-components"></a>
### 2.3 Additional Components

Additional Components for polished case housing:
| Amount    | Component                     |
| --------- | ----------------------------- |
| 1         | [Custom PCB](#)               |
| 1         | [Custom Case](#)              |

**[Back to Top](#toc)**

<a name="implementation"></a>
## 3. Implementation

### Sections
> 3.1 [Hardware](#hardware-implementation)

> 3.2 [Software](#software-implementation)

<a name="hardware-implementation"></a>
### 3.1 Hardware

XXX

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
Gehäuse
1.	Gehäuse vorbereiten (Bohrungen und Aussparungen für Encoder, etc.)
2.	Hardware in das Gehäuse verbauen.

<a name="software-implementation"></a>
### 3.2 Software

XXX

Setup
1.	Die Arduino IDE installieren
2.	In der Arduino IDE die Teensyduino-Erweiterung installieren
3.	Den Teensy über ein USB-Kabel am PC anschließen
4.	In der Arduino DIE:
a.	Das korrekte Board auswählen (Werkzeuge/Board/Teensyduino/…)
b.	Den korrekten USB-Port auswählen (Werkzeuge/Port/…)
c.	Den Code löschen und das verwendetet Skript einfügen
Script
Für das Projekt wurde folgendes Skript verwendet:
https://github.com/PaulToast/Teensy-Delay-Pedal/blob/main/DelayScript.ino
Eigenes Skript erstellen
Für die Erstellung eines eigenen Skripts wird die Verwendung des Audio System Design Tool for Teensy Audio Library empfohlen. Über das visuelle Interface können Signalwege konfiguriert werden und als Teensyduino Code exportiert werden. Falls Bedienelemente verwendet werden (Dreh-Encoder, etc.), müssen diese anschließend noch im Skript implementiert werden.

**[Back to Top](#toc)**