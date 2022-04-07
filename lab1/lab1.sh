echo "Lab № 1 "
echo "This program checks the presence of checksums on a CD. If not, do adds a checksum to the content, if it does, it outputs the value and checks the CD image for correctness."
echo "Script author: Vdovina Irina from 738-1"
while true; do
echo " "
	read -p "Enter the path to the CD: " path_CD	
	if [ -e "$path_CD" ]
		then
		echo " "
		echo "We continue to work."
		echo " "
		echo "The checksums of the CD are being checked." 

		znach=$( checkisomd5 $path_CD 2>&1 )
		proverka=$znach | awk '/NA/'
		proverka2=$znach | awk '/FAIL/'
		echo $proverka	
		if [ "$proverka" = "" ] || [ "$proverka" = "" ]; then
		        echo " "
	                echo "CD checksum found: "
			znach2=$( checkisomd5 --md5sumonly $path_CD 2>&1 )
			echo $znach2
			echo ""
			echo "Checking the validity of the CD: "
			proverka2=$znach2 | awk '/PASS/'
			if [ "proverka2" = "" ]; then
			        echo "The CD image is correct."
			else
			        echo "The CD image is not correct."
			        fi	        	
		else
		        echo " "
		        echo "CD checksum not found."
			echo ""
			echo "Implanting a checksum into the CD image."
			echo ""
			echo "The checksum is: "
			znach1=$( implantisomd5 $path_CD 2>&1 )
			echo $znach1
		        fi
	else 
		echo "There is no such file."
		fi
echo " "
	echo "Do you want to continue? (y/n)"
	read yn
        if [ $yn = "y" ]
        then continue
        else break
        fi
        
done
