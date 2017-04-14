for f in $(find . -iname "*.h")
do
    mv $f ${f%%.h}".hpp"
done
