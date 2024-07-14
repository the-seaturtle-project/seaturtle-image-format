# Seaturtle Image Format (`.stif`)

## File Structure:

### Start Byte
The first byte of the file is 0xFF

### Version Byte
The second byte of the file denotes the `.stif` version
A version byte of 0xXY would mean `.stif` version X.Y

### Width Bytes
The third and fourth bytes of the file holds the width of the file.

### Image Data
Image data is stored in chunks of 25 bytes
The first byte of the chunk stores opacity data.
- Opacity in `.stif` files can only be `0` or `1`
- The opacity byte holds the opacity data for the next 8 pixels.

The second, third, and fourth byte denote the data for the first pixel.
- The second byte holds the value for the `Red` channel
- The third byte holds the value for the `Green` channel
- The fourth byte holds the value for the `Blue` channel

Similarly, the fifth, sixth, and seventh byte denote the data for the second pixel, and so on.

### End Byte
The last byte of the file is 0xFF
