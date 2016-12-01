
# need to load color.sh first
if [[ -z $FONT_COLOR_RED ]]; then 
    echo "Need to load color.sh first" && exit 255
fi

. "$ThisBin"/functions/basic.sh
. "$ThisBin"/functions/alignment.sh
