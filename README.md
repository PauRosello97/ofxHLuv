# ofxHLuv

ofxHLuv is an implementation of HLuv for OpenFrameworks. HLuv is a perceptually uniform color space with a constant luminance. 

## Installation

Download this repository in your addons folder

```bash
$ cd ../addons/
$ git clone https://github.com/PauRosello97/ofxHLuv/
```

## Usage

```c++
#include "ofxHLuv.h";

float hue = 30; // Hue from 0 to 360
float luminance = 60; // Luminance from 0 to 100
ofSetColor(HLuv.getColor(hue, luminance));
ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.


## License
[MIT](https://choosealicense.com/licenses/mit/)
