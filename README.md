# Affine_Cipher

The affine cipher is a type of monoalphabetic substitution cipher, where each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter.
The formula used means that each letter encrypts to one other letter, and back again, meaning the cipher is essentially a standard substitution cipher with a rule governing which letter goes to which.
As such, it has the weaknesses of all substitution ciphers. Each letter is enciphered with the function (ax + b) mod 26, where b is the magnitude of the shift.

Using:

1. Make new object of AffineCipher. Paste as arguments path to your file, value of a and value of b.
2. Choose func encode() or decode().
   2.1 Note that after the encode() function inside the object, the variable path changes to the path to the encrypted file. This means that you won't need to call the changePath() function to apply the decode() method right after encode()
3. Enjoy! You have created a file 'name.ENCODE' and 'DECODEname' in the same directory as your original file.

Using frequency analyzer:
1. Make new object of FrequencyAnalyzer. Paste as arguments path to your encrypted file and path to your original/decrypted file.
2. Use analyzeFromEngTable() method to print information.
