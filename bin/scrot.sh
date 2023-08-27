#!/bin/sh -e
scrot -bfis -l color='Light Sea Green' -F -  \
    | convert PNG:- -sample '200x 200<' PNG:- \
    | xclip -selection clip -t image/png
