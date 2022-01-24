#!/bin/sh

# Check to see if jq is installed.  If not, prompt to install and exit.

INSTALLED=`which jq`
if [ "$INSTALLED" = "" ]
then
    echo "Error:  jq package not found." >&2
    echo "To resolve, install jq package using package manager and try again." >&2
    exit 1
fi

# Do the magic here.  It's gross, but seem to work.  We use sed to massage
# the file into a more digestable json format and let jq do its work.

cat $1 | sed -e 's/.*\[\(.*\)\].*/\1/' | sed -e 's/{}/"-"/g' | sed -e '1s/^/\[/' | sed -e '$s/$/\]/' | jq -r '(map(keys) | add | unique) as $cols | map(. as $row | $cols | map($row[.])) as $rows | $cols, $rows[] | @csv'
