#!/usr/bin/python3

import os
import re
import sys


def read_file(filename):

    """ Lis le fichier passe en parametre et retourne son contenu."""


def find_test_segments(data):

    """ Retourne la liste des segments de doctests dans data."""

    # re.MULTILINE signifie que la regex s'applique sur plusieurs lignes
    # re.DOTALL signifie que '.' capture egalement les sauts de lignes


def extract_tests_from_segment(segment):

    """ Extrait les tuples de tests des segments."""

    # Nettoyer les symboles de commentaires en debut de ligne

    # Separer le segment en lignes

    # Pour chaque ligne, si une entree, ajouter au string d'entrees
    # si une sortie attendue, ajouter au string de sortie attendu

    return (in_source, out)


def write_test_files(tests):

    """ Ecris les tests dans leur fichiers respectifs
        Si le dossier de tests n'existe pas, il est cree."""

    test_dir = sys.argv[2]

    # Verifie l'existance du dossier test et le cree au besoin

    # Ecris les tests dans les fichiers .in et .out


def main():

    # Recuperer le contenu du fichier
    data = read_file(sys.argv[1])

    # Obtenir les blocs de commentaire avec des doctests
    segments = find_test_segments(data)

    # Extraire le test de chaque segment de commentaire
    # Ceci est une comprehension de liste.
    # Le resultat est le meme que de faire:
    #
    # tests = []
    # for seg in segments:
    #     tests.append(extract_tests_from_segment(seg))
    #
    # Plus propre, plus concis et plus efficace
    tests = [extract_tests_from_segment(seg) for seg in segments]

    write_test_files(tests)


def check_args():
    if len(sys.argv) != 3:
        print("Usage: %s <source_file> <test_dir>" % sys.argv[0])
        print("Example:\n\t%s stack.h tests" % sys.argv[0])
        sys.exit()


if __name__ == '__main__':
    check_args()
    main()
