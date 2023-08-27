#!/bin/bash -e
get_random_element() {
	local arr=("$@")
	printf '%s\n' "${arr[RANDOM % $#]}"
}

declare -a wallpapers=("$HOME"/.local/share/backgrounds/*)
hsetroot -fill "$(get_random_element "${wallpapers[@]}")"
