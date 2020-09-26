# ASRealize1

## Documentation

ASRealize1 is an interpreter written in C++, developed for the ASRscript (standard alpha) language, which is used to describe graphics for an ASR renderer.


## Get started


In comparison to the ASR library, ASRealize1 contains SDL already so there is no need to download SDL.
You just have to download the latest release and then you can start using it to interpret your ASRscript files.


## Interpret an ASRScript file


ASRScript files have the .asr extension.
In order to run a .asr file open up your terminal and navigate to the directory, where the asr binary is located.
Now type in the following command into your command line

```
asr -asr <path to your .asr file> <the amount of time for how long the render should be displayed>
```

Now press enter and see your ASRscript code being realized.


## Getting information about the ASRealize1 interpreter


To get information about the ASRealize interpreter navigate to the directory, where the asr binary is located.
Now type in the following command into your command line

```
asr -ver
```

## How does ASRealize1 work?

The interpretation process consists of 5 phases:
  * File handling
  * Initialization
  * Body handling
  * Lexing
  * Extraction
  * Execution
  * Presentation
  
The phases and their order are realized throgh this scheme.

![schemeimage](https://raw.githubusercontent.com/anotherSimpleCoder/asrealize-1/master/misc/Interpretation_scheme.jpg)

These phases are being realized and excuted by so called "modules":
  
  * File Handler
  * Initializer
  * Body Handler
  * Lexer
  * Extractor
  * Executer
  * Presenter
  
  
### File Handler

The File Handler module is responsible for the File handling phase (first phase). 
The module loads the .asr file into the interpreter. Also it check if the inputted file is a valid
ASRscript file by looking for the ```meta``` expression. If the check is positive the interpreter continues to the next phase: the Initialization, which is handled by the Initializer module.

### Initializer

As explained before the Initializer module handles the Initialization phase.
In this phase the module extracts the data from the meta section of the .asr file, which is in this case the screen resolution for the render/window and the block size.
The extracted data will then be stored in its respective variables. Now it sets up the framework with the values of the variables.
After this process the Interpreter proceeds to the Body Handling phase.

### Body Handler

The Body Handler module is responsible for the Body Handling phase. 
It first of all skips through the file until the ```body``` expression is found.
After that it will start to go thorugh each line of the file. One line will be stored in a string variable and that variable will be handed over to the Lexer. This process repeats itself until the end of file is reached.

### Lexer

The Lexer recieves a string from the Body Handling module. Each character of the string will be inspected and converted to tokens.
Tokens represent a single character of the code. These tokens are used to construct a model of the instruction, which is giving the Interpreter information about the way the instruction is structured. These tokens are saved in a LinkedList to the according order. Except tokens, the Lexer also looks for numeric values, which will then be saved in another LinkedList. The property of the number is determined by the position of the number in the Value list:


| Position      | Property                                          |
|:-------------:|:-------------------------------------------------:|
| 0             | X coordinate of the block position                |
| 1             | Y coordinate of the block poition                 |
| 2             | The red value of the RGBA color for the block.    |
| 3             | The green value of the RGBA color for the block.  |
| 4             | The blue value of the RGBA color for the block.   |
| 5             | The alpha value of the RGBA color for the block.  |

After this whole process the Interpreter continues with the extraction phase.

### Extractor

The Extractor is the module responsible for the Extraction phase. The Extractor now goes through the token list to check that the instruction is syntactially correct and also extracts the values out of the Value List and as explained before the values will be stored in the variables according to their position in the Value List.

Now the Interpreter goes over to the Execution phase.

### Executor

The Executor module handles the Execution phase by creating all the variables needed for executing the instruction with the extracted data, which we got from the Extraction process. This means that the 2 dimensional vector, which is used for describing the block's position and the colorDim, which is used to specify the color in which the block needs to be rendered in are being created and given to the already initialized renderer. Now we are in the final stage, which is the Presentation.

### Presenter

The Presenter module, which is responsible for the Presentation phase presents the finished render onto the already initialized window and will be shown for a time in ms, which has to be specified in the command line arguments.


Some final words
----------------
Hello there! So I hope my documentation was somewhat easy to understand and follow. If that wasn't the case feel free to contact me! (My email address is given in the version information of ASRealize1. This is my first interpreter and the first "script" language I concipated and developed. It was a quite fun process and there are many more things to come in the upcoming versions of the ASRealize Interpreter and ASRcript standards. Also if you experience and bugs or want to give me feedback for the Interpreter just send me an email and I will try to answer you as soon as possible and will consider your feedback / fix the bug.

So here are some features I am planning for the ASRscript language and ASRealize:

  * variables
  * loops
  * sequences (A collection of instructions)
  * arithmetic operations
  * optimizing the ASR library and the Interpretation process
  
 If you have any ideas, which can be added to this project then feel free to share it with me via email.
 Also binary for macOS and the documentation for ASRscript will be released in the coming days. 
 (although it's a hard to handle)
