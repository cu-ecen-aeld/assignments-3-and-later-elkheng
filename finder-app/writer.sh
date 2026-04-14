writefile=$1
writestr=$2

if [ $# -lt 2 ]
then
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi
if [ -f "$writefile" ]
then
    rm -f "$writefile"
fi

filesdir=$(dirname "$writefile")
if [ ! -d "$filesdir" ]
then
    mkdir -p "$filesdir"
fi

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]
then
    echo "Error: Failed to write to $writefile"
    exit 1
fi
