# 🧠 ArduinoWorkshop_Biosignals
### Biosignals & Biopotentials — University Workshop

> **Plug-and-play Arduino code blocks for reading EEG, EMG & ECG biosignals.**  
> Built for undergrads from all streams. Zero prior experience needed. 🧱

---

## 🚀 Quick Start

1. **Clone or download** this repository
2. Open any `.ino` block in **Arduino IDE**
3. Connect your sensor, click **Upload ▶**
4. Open **Tools → Serial Plotter** and watch your biosignal live!

---

## 📁 Repository Structure

```
ArduinoWorkshop_Biosignals/
│
├── 🌐 index.html                        ← Open in browser for the full presentation
├── 📖 WORKSHOP_GUIDE.md                 ← Step-by-step attendee guide
│
├── 🧱 Block_01_ADC_BasicRead/           ← Start here! Read any analog sensor
├── 🧱 Block_02_EMG_Reader/              ← Read & detect muscle signals
├── 🧱 Block_03_ECG_Reader/              ← Read heart PQRST waveform (AD8232)
├── 🧱 Block_04_EEG_Serial/              ← High-speed EEG streaming + CSV export
├── 🧱 Block_05_SignalFilter/            ← Low-pass + notch filter demo
└── 🧱 Block_06_FullPipeline/            ← Complete end-to-end biosignal pipeline
```

---

## 🧱 The Blocks

| Block | File | What it does | Sensor |
|-------|------|-------------|--------|
| 01 | `Block_01_ADC_BasicRead.ino` | Read raw ADC + convert to voltage | Any analog sensor |
| 02 | `Block_02_EMG_Reader.ino` | EMG signal + smoothing + activation detection | MyoWare / generic EMG |
| 03 | `Block_03_ECG_Reader.ino` | ECG PQRST stream + leads-off detection | AD8232 |
| 04 | `Block_04_EEG_Serial.ino` | High-speed CSV stream for analysis | Generic EEG front-end |
| 05 | `Block_05_SignalFilter.ino` | Software low-pass + notch filter | Any analog sensor |
| 06 | `Block_06_FullPipeline.ino` | Read → Filter → RMS → Detect → Output | Any biosignal sensor |

---

## 🎓 Presentation

Open `index.html` in any browser for the full workshop slide deck.

**Controls:**
| Key | Action |
|-----|--------|
| `→` or `Space` | Next slide |
| `←` | Previous slide |
| `F` | Fullscreen |
| `Home` / `End` | First / Last slide |
| Swipe | Touch devices |

---

## ⚙️ ADC Reference

| Board | ADC Bits | Max Value | Change in code |
|-------|----------|-----------|----------------|
| **Arduino Uno** ✅ | 10-bit | 1023 | `1023.0` (default) |
| **Arduino Nano** ✅ | 10-bit | 1023 | `1023.0` (default) |
| ESP32 | 12-bit | 4095 | `4095.0` |
| STM32 | 12-bit | 4095 | `4095.0` |

---

## 🔌 Hardware Wiring

### EMG (MyoWare)
```
MyoWare SIG → A0
MyoWare VCC → 5V
MyoWare GND → GND
```

### ECG (AD8232)
```
AD8232 OUTPUT → A0
AD8232 LO+    → Pin 10
AD8232 LO-    → Pin 11
AD8232 VCC    → 3.3V  ⚠️ NOT 5V
AD8232 GND    → GND
```

---

## 📜 License

MIT — Free to use, share, and modify. Please credit the workshop if you reuse! 🙏

---

*Made with ❤️ by **Adhavaa** & **Seraphim** for the Biosignals & Biopotentials Workshop*