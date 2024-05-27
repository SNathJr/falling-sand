# Falling Sand Simulation

This project is a falling sand simulation using SDL2, designed to be built and run either as a native application or as a web application using Emscripten. 
The build script provided supports cleaning the build directory and setting the target platform.

## Prerequisites

### Native Build
- `g++` (GNU Compiler Collection)
- `SDL2` development libraries

### Web Build
- `Emscripten` SDK
- `SDL2` development libraries

## Installation

### SDL2 Installation

#### Ubuntu
```sh
sudo apt-get install libsdl2-dev
```

#### macOS
```sh
brew install sdl2
```

### Emscripten Installation

Follow the instructions on the [Emscripten website](https://emscripten.org/docs/getting_started/downloads.html) to install the SDK.

## Building and Running

### Build Script

The build script `build.sh` supports the following options:
- `clean`: Cleans the build directory before building.
- `native`: Builds the project as a native application.
- `execute`: Executes the project as once build is complete.
- Default (no arguments): Builds the project as a web application.

### Usage

#### Build for Web (Default)

To build and run the project as a web application, simply run the script without any arguments:

```sh
./build.sh
```

To additionally start a local http server use:

```sh
./build.sh execute
```

This will build the project for the web and start a local HTTP server to serve the application.

#### Build for Native

To build the project as a native application, use the `native` argument:

```sh
./build.sh native
```

The native executable will be located in the `build` directory as `main.elf`.

To additionally execute the built file, use:

```sh
./build.sh execute native
```

#### Clean and Build

To clean the build directory before building, use the `clean` argument:

##### Clean and Build for Web

```sh
./build.sh clean
```

##### Clean and Build for Native

```sh
./build.sh clean native
```

## References

### Color Palette

We will be using Dracula Color Palette. You can find more info here [Dracula Contributions](https://draculatheme.com/contribute).

| Palette      | Hex       | RGB           | HSL             | ![Color Picker Boxes](https://draculatheme.com/images/color-boxes/eyedropper.png)   |
| ------------ | --------- | ------------- | --------------- | ----------------------------------------------------------------------------------- |
| Background   | `#282a36` | `40 42 54`    | `231° 15% 18%`  | ![Background Color](https://draculatheme.com/images/color-boxes/background.png)     |
| Current Line | `#44475a` | `68 71 90`    | `232° 14% 31%`  | ![Current Line Color](https://draculatheme.com/images/color-boxes/current_line.png) |
| Selection    | `#44475a` | `68 71 90`    | `232° 14% 31%`  | ![Selection Color](https://draculatheme.com/images/color-boxes/selection.png)       |
| Foreground   | `#f8f8f2` | `248 248 242` | `60° 30% 96%`   | ![Foreground Color](https://draculatheme.com/images/color-boxes/foreground.png)     |
| Comment      | `#6272a4` | `98 114 164`  | `225° 27% 51%`  | ![Comment Color](https://draculatheme.com/images/color-boxes/comment.png)           |
| Cyan         | `#8be9fd` | `139 233 253` | `191° 97% 77%`  | ![Cyan Color](https://draculatheme.com/images/color-boxes/cyan.png)                 |
| Green        | `#50fa7b` | `80 250 123`  | `135° 94% 65%`  | ![Green Color](https://draculatheme.com/images/color-boxes/green.png)               |
| Orange       | `#ffb86c` | `255 184 108` | `31° 100% 71%`  | ![Orange Color](https://draculatheme.com/images/color-boxes/orange.png)             |
| Pink         | `#ff79c6` | `255 121 198` | `326° 100% 74%` | ![Pink Color](https://draculatheme.com/images/color-boxes/pink.png)                 |
| Purple       | `#bd93f9` | `189 147 249` | `265° 89% 78%`  | ![Purple Color](https://draculatheme.com/images/color-boxes/purple.png)             |
| Red          | `#ff5555` | `255 85 85`   | `0° 100% 67%`   | ![Red Color](https://draculatheme.com/images/color-boxes/red.png)                   |
| Yellow       | `#f1fa8c` | `241 250 140` | `65° 92% 76%`   | ![Yellow Color](https://draculatheme.com/images/color-boxes/yellow.png)             |

## Project Structure

```
.
├── assets             # Assets directory
├── build              # Build directory (generated during build process)
├── index.html         # HTML file for the web build
├── main.cpp           # Main source file
├── build.sh           # Build script
└── README.md          # This README file
```

## Troubleshooting

### Common Issues

- **SDL2 Not Found**: Ensure SDL2 is installed and the development libraries are available on your system.
- **Emscripten Not Found**: Ensure the Emscripten SDK is installed and sourced correctly.

### Error Messages

- **Web Build Failed**: Ensure Emscripten is installed and properly configured.
- **Native Build Failed**: Ensure `g++` and SDL2 development libraries are installed.

## License

This project is licensed under the MIT License.
