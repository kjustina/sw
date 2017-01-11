#!/bin/sh

warn () {
  echo "$@" >&2
}

die () {
  status="$1"
  shift
  warn "$@"
  exit "$status"
}

# perform ping test between two VMs
vagrant ssh -c "ping -c 5 node2" node1
ret=$?
if [ $ret == "" ]; then
  die 1 "Ping test failed!!"
fi

vagrant ssh -c "go version" node1
ret=$?
if [ $ret == "" ]; then
  die 1 "Go not installed!!"
fi

LIMIT=10
for a in $(seq 1 $LIMIT)
do
  # check if all nodes are running
  numRunning=`vagrant ssh -c "kubectl get nodes" node1 | grep Ready | wc -l`
  echo $numRunning nodes are running
  if [ "$numRunning" -ge 2 ]
  then
    echo "All nodes are running"
    break
  fi

  # Check if we exceeded the loop
  if [ "$a" -ge $LIMIT ]
  then
    die 1 "All nodes are not running. Failing test"
  fi

  sleep 10
done

exit 0
