# Example Project: Hill Cipher Mat26

[![EP](https://raw.githubusercontent.com/tobiasbriones/images/main/example-projects/ep-hill-cipher-mat26/badge.svg)](https://tobiasbriones.github.io/example-project/ep/hill-cipher-mat26)
&nbsp;
[![GitHub Repository](https://raw.githubusercontent.com/tobiasbriones/general-images/main/example-projects/badges/ep-gh-repo-badge.svg)](https://github.com/tobiasbriones/ep-hill-cipher-mat26)

[![GitHub Project License](https://img.shields.io/github/license/tobiasbriones/ep-hill-cipher-mat26.svg?style=flat-square)](https://github.com/tobiasbriones/ep-hill-cipher-mat26/blob/main/LICENSE)

Example project for a Hill Cipher algorithm with a Matrix under the Z26 field implementation.

**In short:**

- You can check out the test file to understand the concepts implemented into this source files.

- There is an implementation of a SquareMatrix which is a normal square matrix with common
  operations, and a subclass of this matrix which is a SquareMatrix26 which works under the field
  Z26.

- The Alphabet26 struct helps the algorithm to be computed by providing the English alphabet of 26
  characters (`A-Z`). As you know, the character "A" in ASCII has the decimal value of 65 so that
  this struct is a representation of the integers modulo 26 (Z26).

- Finally, there is the HillCipher implementation made possible by the aforementioned tools.

The program is executed and reads the text file (dec.txt) which contains a message that can be
encrypted, and saved into the other file (enc.txt), then it reads the other file (enc.txt), decrypts
the secret message and saves it into the dec.txt file. Also, notice that the key is set to the
algorithm prior to proceeding to encrypt or decrypt.

More work that can be done on this program is to add more operator overloading and tests to verify
if everything is working fine.

## Contact

This project: [Repository](https://github.com/tobiasbriones/ep-hill-cipher-mat26)

Tobias Briones: [GitHub](https://github.com/tobiasbriones)

Example Project: [App](https://tobiasbriones.github.io/example-project)

## About

**Example Project: Hill Cipher Mat26**

Example project for a Hill Cipher algorithm with a Matrix under the Z26 field implementation.

Copyright © 2021 Tobias Briones. All rights reserved.

### License

This project is licensed under the [MIT License](./LICENSE).
