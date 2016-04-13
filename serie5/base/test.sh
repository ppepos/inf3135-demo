#!/bin/bash

for f in `ls tests/*in`
do
	# Trouver le fichier .out associe
	# Ecrire le fichier a compiler pour le test. Il faut un main.

	# Compiler le test genere

	# Executer le test et rediriger la sortie dans un fichier

	# Comparer la sortie au fichier contenant la sortie attendue
	# Enlever la redirection et le -q pour deboguer
	# diff tests/temp.out $out_file

	diff -q tests/temp.out $out_file 1>/dev/null
	if [[ $? == "0" ]]; then
		echo "$f : OK"
	else
		echo "$f : FAILED"
	fi

	# Nettoyer (supprimez) vos fichiers temporaires
done
