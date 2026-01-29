# 🔐 Password Entropy & Strength Calculator (C++)

A lightweight **C++ command-line tool** that estimates the **entropy** and **brute-force cracking time** of a password based on its length and character set diversity.  
This project implements a classical password-strength model commonly referenced in cryptography and security research.

---

## 📌 Features

- Calculates **password entropy (in bits)**
- Estimates **brute-force cracking time**
- Supports:
  - Lowercase letters (`a–z`)
  - Uppercase letters (`A–Z`)
  - Numbers (`0–9`)
  - Punctuation / special characters
- Assumes **1 billion guesses per second**
- Single-file implementation (`.cpp`)
- Portable and easy to compile

---

## 🧠 Entropy Model

Password entropy is calculated as:

\[
\text{Entropy} = L \times \log_2(N)
\]

Where:
- `L` = password length  
- `N` = size of the combined character set used  

The cracking time estimate assumes a **uniform random password** and no dictionary-based optimizations.

---

## 🗂️ Project Structure

