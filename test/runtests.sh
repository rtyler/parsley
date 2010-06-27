#!/bin/bash +x

PARSLEY=../parsley
SUCCEEDED=
FAILED=

for prefix in $(ls *.let | sed 's/.let//g'); do 
    echo -n ">> Testing ${prefix}.let...";
    INPUT_FILE="${prefix}.html"
    P_OPTIONS=

    if [ -a $INPUT_FILE ]; then
        echo -n ".."
    else
        INPUT_FILE="${prefix}.xml"
        P_OPTIONS+=" -x "
    fi

    if [ "${prefix}" = "sg-wrap" ]; then
        P_OPTIONS+=" -s "
    fi


    ${PARSLEY} ${P_OPTIONS} "${prefix}.let" "${INPUT_FILE}" 2>&1 | diff "${prefix}.json" -  
    
    if [ $? -ne 0 ]; then
        echo 
        echo ">>>> Test failed: ${prefix}"
        echo
        FAILED+=" ${prefix}"
    else
        echo " success";
        SUCCEEDED+=" ${prefix}"
    fi
done

echo
echo "Succeeded: ${SUCCEEDED}"
echo
echo "Failed: ${FAILED}"
echo
