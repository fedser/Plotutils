#!/bin/sh

png_support=$(grep INCLUDE_PNG_SUPPORT config.h)
#echo $png_support
if [ "$png_support" ]; then
	sed -i "58a$png_support"  include/plotter.h
fi
