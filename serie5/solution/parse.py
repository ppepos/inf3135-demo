#!/usr/bin/python3

import os
import re
import sys


def read_file(filename):

    """ Lis le fichier passe en parametre et retourne son contenu."""

    data = None
    with open(sys.argv[1], "r") as fd:
        data = fd.read()
    return data


def find_test_segments(data):

    """ Retourne la liste des segments de doctests dans data."""

    # re.MULTILINE signifie que la regex s'applique sur plusieurs lignes
    # re.DOTALL signifie que '.' capture egalement les sauts de lignes
    test_re = re.compile("TESTS:\s*.*?\s*\*/", re.MULTILINE | re.DOTALL)
    return re.findall(test_re, data)


def extract_tests_from_segment(segment):

    """ Extrait les tuples de tests des segments."""

    in_source = []
    out = []

    # RE pour nettoyer les symboles de commentaires en debut de ligne
    line_start_star = re.compile("\s*\*\s*/?")

    # Separer le segment en lignes
    lines = segment.split("\n")

    # On garde lines[1] jusqua la fin (retirer la premiere ligne "TESTS:"
    lines = lines[1:]

    for line in lines:
        line = line.strip()  # strip enleve les espaces blancs autour
        line = re.sub(line_start_star, "", line)  # enlever les " * "

        # Traiter les sorties (resultats attendus)
        if line.startswith(">>>"):
            line = line.replace(">>>", "")
            line = line.strip()
            out.append(line)

        # Et les entrees
        else:
            in_source.append(line)

    # Transformer la liste de lignes en un seul string en les joignant avec des
    # sauts de lignes. ["abc", "def"] --> "abc\ndef"
    in_source = "\n".join(in_source)
    out = "\n".join(out)
    out += "\n"  # Bonne pratique d'avoir \n comme dernier byte.

    return (in_source, out)


def write_test_files(tests):

    """ Ecris les tests dans leur fichiers respectifs
        Si le dossier de tests n'existe pas, il est cree."""

    test_dir = sys.argv[2]

    # Verifie l'existance du dossier test et le cree au besoin
    if not os.path.isdir(test_dir):
        os.makedirs(test_dir)

    # Ecris les tests dans les fichiers .in et .out
    for index, test in enumerate(tests):
        with open("tests/test%s.in" % index, 'w') as fd_in, \
                open("tests/test%s.out" % index, 'w') as fd_out:
            fd_in.write(test[0])
            fd_out.write(test[1])


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
