# mydesktop-cw 

_previously known as dwm-based "Desktop Environment" (dwmbde)_

After moving back from Windows, I felt pretty unsatisfied with [suckless-cw](https://github.com/cwillsey06/suckless-cw), and wanted a new, mostly polished desktop experience.  
so here's that :3

## Installation

While there are no install instructions / scripts at the moment, I can give a quick explanation on _what I do_:

* `cd` to each software dir and `make`
* `ln -s "$PWD"/{binary} "$HOME"/.local/bin`
* `cd` to rootdir and `ln -s "$PWD"/bin/* "$HOME"/.local/bin`
* `cd` to rootdir and `ln -s "$PWD"/picom.conf "$HOME/.config/`
* set `.xinitrc` to
```
#!/bin/sh -e
export "$(dbus-launch)"

pipewire &
pipewire-pulse &

picom --config "$HOME"/.config/picom.conf &
"$HOME"/.local/bin/random-wp.sh &

slstatus &
dwm
```

i think that's it.

## Licensing

dwm, st, slstatus and dmenu are all developed by the amazing folks @[suckless.org](https://suckless.org/)  
License information is retained in their respective codebases at the root of this repository.
