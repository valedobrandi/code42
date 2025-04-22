Compilation
Il devrait être possible de compiler le projet avec les flags habituels
et le flag -D BUFFER_SIZE. Il doit être possible de compiler ce projet avec et sans
ce dernier en plus des flags : -Wall -Wextra -Werror. S'il y a une erreur,
l'évaluation s'arrête ici. Vous pouvez continuer et discuter de la mise en
œuvre du code, mais la soutenance ne sera pas noté.

Gestion d'erreur
Effectuez au minimum les tests d'erreur suivants afin de vérifier la
gestion d'erreur du programmme.

Passez un fd arbitraire a la fonction get_next_line, sur lequel il n'est pas possible de lire (par ex. 42) La fonction doit renvoyer NULL.
Vérifiez les retours d'erreur de malloc, read et open. Si la partie "gestion d'erreur" est fausse, merci de ne pas noter la partie suivante, la correction s'arrête ici. Vous pouvez continuer et discuter de l'implémentation du code, mais cela ne sera pas noté.
Tests
En temps qu'évaluateur(ice), vous devez écrire ou apporter un main qui vérifie :

La valeur de retour de la fonction get_next_line est NULL en cas d'erreur.
Sinon, la fonction renvoie la ligne lue, toujours avec un \n à la fin.
Testez toutes les combinaisons des règles suivantes :

Gros BUFFER_SIZE (> 1024)
Petit BUFFER_SIZE (< 8, et 1)
BUFFER_SIZE de la taille de la ligne à lire
1 de décalage (+/-) entre le BUFFER_SIZE et la ligne

Lecture depuis stdin

Lecture depuis un fichier

(Multiple/Simple) ligne longue (2k+ caractères)

(Multiple/Simple) ligne courte (<4 caractères, et 1)

(Multiple/Simple) Ligne vide

Ces tests devraient vous permettre de vérifier la validité du projet de
l'étudiant(e). En cas d'erreur, l'évaluation s'arrête ici.
