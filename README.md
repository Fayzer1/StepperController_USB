# Хронология разработки
### 1. Структурная схема
<img width="1201" height="842" alt="image" src="https://github.com/user-attachments/assets/c113f6ba-7148-43bb-936a-a6c1f948d9f4" />


Были проанализированы существующие схематические решения и компонентная база и выбраны соответственные основные компоненты:
STM32F103C8T6, наиболее распространённый и бюджетный микроконтроллер
STM L298N, был выбран из-за того, что не требует сложной топологии электронной ячейки и имеет крепление радиатора.
STM L297D, используется для формирования сигналов, необходимых для силового драйвера L298N, который обычно идет в связке с ним.
Пассивные компоненты преимущественно в SMD исполнении.

### 2. Принципиальная схема

<img width="1196" height="843" alt="image" src="https://github.com/user-attachments/assets/67de48d2-48cb-421b-8656-7c091277990a" />


### 3. Топология ячейки
<img width="1051" height="850" alt="image" src="https://github.com/user-attachments/assets/7378cad1-318a-4f25-8334-72cbbd28e86d" />

### 4. Чертеж печатной платы

<img width="1170" height="821" alt="image" src="https://github.com/user-attachments/assets/ca1aba9c-2c50-4854-a6a6-738a1c576658" />


### 5. Сборочный чертеж ячейки
<img width="1089" height="762" alt="image" src="https://github.com/user-attachments/assets/3bf9f1c1-2c7d-4b0a-887a-a97a912a8a63" />


### 6. Сборочный чертеж устройства
<img width="1162" height="817" alt="image" src="https://github.com/user-attachments/assets/1d7f51ab-f488-433f-bc84-9cfca7318c36" />

### 7. 3D Вид
<img width="827" height="561" alt="image" src="https://github.com/user-attachments/assets/382fd1c5-452d-4123-96d6-e2f10a6e2024" />
<img width="827" height="678" alt="image" src="https://github.com/user-attachments/assets/839e78ce-0b72-4fe7-a30e-221b563c397e" />

##### 3D вид электронной ячейки (из KiCad)

<img width="750" height="598" alt="image" src="https://github.com/user-attachments/assets/dde303e6-48c6-4b10-98c1-f281ca9de6d0" />

<img width="716" height="569" alt="image" src="https://github.com/user-attachments/assets/029d7ef5-d922-4a60-a835-44378799e280" />


<img width="895" height="585" alt="image" src="https://github.com/user-attachments/assets/3e388384-aaa0-4268-b682-4550952afb5b" />


### 8. Моделирование теплового режима
<img width="927" height="911" alt="image" src="https://github.com/user-attachments/assets/b859d751-1c82-46b2-99cd-abb2d25456d1" />

### 9. Моделирование механических воздействий

##### Искажение формы электронного модуля на первой собственной частоте(увеличение деформаций для наглядности)

<img width="886" height="622" alt="image" src="https://github.com/user-attachments/assets/9aeed4c9-fa1a-47f7-aa20-7ec10b15ec78" />

##### Эпюра напряжений

<img width="898" height="570" alt="image" src="https://github.com/user-attachments/assets/7cd62afe-e576-46c7-b966-0532f0e24d82" />

##### Перемещение электронного модуля при действии ударного ускорения

<img width="825" height="526" alt="image" src="https://github.com/user-attachments/assets/c60c7e09-9dc7-4dea-9cae-cc0811f1581a" />

---
### Проверка работоспособности устройства 

Введена команда HELP

<img width="679" height="508" alt="image" src="https://github.com/user-attachments/assets/256aa693-d821-457e-b057-7145e1760936" />

Проверка команд запуска и остановки тактовых импульсов

<img width="709" height="485" alt="image" src="https://github.com/user-attachments/assets/9aa77dd0-cc25-4768-85e7-3e2c6fa7f6a5" />

Осциллограмма сигнала STEP, формируемого микроконтроллером

<img width="886" height="664" alt="image" src="https://github.com/user-attachments/assets/2ec128b0-a3d2-4376-9fb0-fbcc9c9c8ba9" />

Проверка обработки неизвестных команд

<img width="450" height="345" alt="image" src="https://github.com/user-attachments/assets/f162a0bd-a3cf-40cf-adb5-f3b5f2be501e" />

Осциллограмма сигналов фаз A и B в полношаговом режиме

<img width="581" height="436" alt="image" src="https://github.com/user-attachments/assets/0d56a857-fef6-4f01-9341-bd3abfed1f80" />

Осциллограмма сигналов фаз A и B в полушаговом режиме

<img width="778" height="584" alt="image" src="https://github.com/user-attachments/assets/cad6eac7-3269-4785-8ba5-96742c70f2d1" />


https://github.com/user-attachments/assets/480870aa-635b-4972-973b-bfc4dbc35d21
 1. Поворот на 90 градусов на низкой скорости
 2. Увеличение скорости и поворот на заданный угол


