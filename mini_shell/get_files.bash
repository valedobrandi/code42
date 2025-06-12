find src -type f -print0 | xargs -0 -n1 basename | sed 's/$/ \\/'
