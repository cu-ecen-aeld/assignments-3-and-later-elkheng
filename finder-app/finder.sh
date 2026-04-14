# filesdir= $(dirname "$(readlink -f "$0")")
# cd "$filesdir"
filesdir=$1
searchstr=$2

if [ $# -lt 2 ]
then
    echo "Usage: $0 <searchdirectory> <searchstring>"
    exit 1
fi

if [ ! -d "$filesdir" ]
then
    echo "Error: $filesdir is not a directory"
    exit 1
fi

numfiles=$(find "$filesdir" -type f | wc -l)
numlines=$(grep -r "$searchstr" "$filesdir" | wc -l)
echo "The number of files are $numfiles and the number of matching lines are $numlines"