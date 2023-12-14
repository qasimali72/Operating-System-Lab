#!/bin/sh

# Function to convert marks into grade
marksToGrade() {
    marks=$1

    if [ $marks -ge 90 ]; then
        echo "A+"
    elif [ $marks -ge 86 ]; then
        echo "A"
    elif [ $marks -ge 82 ]; then
        echo "A-"
    elif [ $marks -ge 78 ]; then
        echo "B+"
    elif [ $marks -ge 74 ]; then
        echo "B"
    elif [ $marks -ge 70 ]; then
        echo "B-"
    elif [ $marks -ge 66 ]; then
        echo "C+"
    elif [ $marks -ge 62 ]; then
        echo "C"
    elif [ $marks -ge 58 ]; then
        echo "C-"
    elif [ $marks -ge 54 ]; then
        echo "D+"
    elif [ $marks -ge 50 ]; then
        echo "D"
    else
        echo "F"
    fi
}

# Function to convert grade into corresponding points
gradeToPoints() {
    choice=$1

    case $choice in
    "A+" | "A")
        echo "4.0"
        ;;
    "A-")
        echo "3.67"
        ;;
    "B+")
        echo "3.33"
        ;;
    "B")
        echo "3.00"
        ;;
    "B-")
        echo "2.67"
        ;;
    "C+")
        echo "2.33"
        ;;
    "C")
        echo "2.00"
        ;;
    "C-")
        echo "1.67"
        ;;
    "D+")
        echo "1.33"
        ;;
    "D")
        echo "1.00"
        ;;
    "F")
        echo "0.00"
        ;;
    *)
        echo "Invalid grade: $choice"
        ;;
    esac
}

# Input prompts
echo "Enter Physics Marks:"
read physics
echo "Enter Math marks:"
read math
echo "Enter English Marks:"
read english
echo "Enter Chemistry marks:"
read chemistry
echo "Enter Computer marks:"
read computer

# Calculate and print results
grade1=$(marksToGrade $physics)
point1=$(gradeToPoints $grade1)
echo "Physics Course:- Marks: $physics, Grade: $grade1, Points: $point1"

grade2=$(marksToGrade $math)
point2=$(gradeToPoints $grade2)
echo "Math Course:- Marks: $math, Grade: $grade2, Points: $point2"

grade3=$(marksToGrade $english)
point3=$(gradeToPoints $grade3)
echo "English Course:- Marks: $english, Grade: $grade3, Points: $point3"

grade4=$(marksToGrade $chemistry)
point4=$(gradeToPoints $grade4)
echo "Chemistry Course:- Marks: $chemistry, Grade: $grade4, Points: $point4"

grade5=$(marksToGrade $computer)
point5=$(gradeToPoints $grade5)
echo "Computer Course:- Marks: $computer, Grade: $grade5, Points: $point5"
