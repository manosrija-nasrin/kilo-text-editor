# antirez's [kilo](https://github.com/antirez/kilo) text editor

### written with the help of [snaptoken's tutorial](https://viewsourcecode.org/snaptoken/kilo/)

A simple text editor with incremental search and syntax highlighting features for C.

### Status

Due for upgrades.

### How to use

I suggest using antirez's [original version](https://github.com/antirez/kilo). To use *this* version, type the following in your terminal.

1. **Clone the repository locally**:

```
git clone https://github.com/manosrija-nasrin/kilo-text-editor.git
cd kilo-text-editor
```

2. **Compile the source code**: `make kilo`
3. **Use the editor**:`./kilo [optional: filename]` for e.g. `./kilo` or `./kilo kilo.c`

### Credit

- followed snaptoken's tutorial. [here](https://viewsourcecode.org/snaptoken/kilo/)
- the original version of kilo text editor by Salvatore Sanfilippo aka [antirez](https://github.com/antirez) | [here](https://github.com/antirez/kilo)

### Ideas for more features

_(from snaptoken's tutorial website itself)_

- **More filetypes**: Add syntax highlighting rules for some of your favourite languages to the `HLDB` array.
- **Line numbers**: Display the line number to the left of each line of the file.
- **Soft indent**: If you like using spaces instead of tabs, make the Tab key insert spaces instead of `\t`. You may want Backspace to remove a Tab key’s worth of spaces as well.
- **Auto indent**: When starting a new line, indent it to the same level as the previous line.
- **Hard-wrap lines**: Insert a newline in the text when the user is about to type past the end of the screen. Try not to insert the newline where it would split up a word.
- **Soft-wrap lines**: When a line is longer than the screen width, use multiple lines on the screen to display it instead of horizontal scrolling.
- **Use ncurses**: The [ncurses](https://en.wikipedia.org/wiki/Ncurses) library takes care of a lot of the low level terminal interaction for you, and makes your program more portable.
- **Copy and paste**: Give the user a way to select text, and then copy the selected text when they press Ctrl-C, and let them paste the copied text when they press Ctrl-V.
- **Config file**: Have `kilo` read a config file (maybe named `.kilorc`) to set options that are currently constants, like `KILO_TAB_STOP` and `KILO_QUIT_TIMES`. Try to make more things configurable.
- **Modal editing**: If you like [vim](http://www.vim.org/), make `kilo` work more like vim by letting the user press i for “insert mode” and then press Escape to go back to “normal mode”. Then start adding all your favourite vim commands, starting with the basic movement commands (hjkl).
- **Multiple buffers**: Allow having multiple files open at once, and have some way of switching between them.

_(my own thoughts)_

- **Expand syntax highlighting features**: Highlight `include`s, `define`, `ifndef`s and other preprocessor directives for C.
- **Undo and redo**: Give the user the option to undo or redo a change when they press Ctrl-Z or Ctrl-Y respectively.
- **Modify cursor snapping**: Snap the cursor to the end of last line in file. The user should not be able to move one line below the last line in file.
