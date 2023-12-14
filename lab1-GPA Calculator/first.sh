#!/bin/bash
echo "Switch statement"

x=$1
case $x in
    $x ge 90)
        echo "The grade is A+"
        ;;
    $x ge 80)  
        echo "The grade is A"
        ;;
    3)
        echo "this is level 3"
        ;;
    *)
        echo "this is my default level"
        ;;
esac
exit 0
