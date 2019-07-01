# stm32f103 template
This repository contains my project template for the STM32F103xx series. This
only requires an ARM compiler/linker and has no dependencies on any code/headers
provided by ST. This was tested on an STM32F103C8, but should work on similar
MCUs from the series.

NOTE1: This code assumes an 8MHz crystal connected, and sets the clock to 72MHz.
NOTE2: Code upload via the Makefile requires an ST-LINK dongle connected.
NOTE3: For serial output connect a TTL serial adapter to USART1_TX (PA9).

## references
[STM32F103C8 Datasheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf)

[STM32F10xxx Reference manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf)

[STM32F10xxx Flash programming manual](https://www.st.com/content/ccc/resource/technical/document/programming_manual/10/98/e8/d4/2b/51/4b/f5/CD00283419.pdf/files/CD00283419.pdf/jcr:content/translations/en.CD00283419.pdf)
