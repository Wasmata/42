# Minishell
Voici une roadmap pour deux personnes, uniquement sur la partie mandatory du projet Minishell. Je te répartis les tâches de manière équilibrée et séquentielle, en indiquant ce qui peut être fait en parallèle ou ce qui dépend d’autres éléments. Le tout peut être réalisé sur 4 à 5 semaines avec un bon rythme.

⸻

Semaine 1 : Setup & Parsing de base

Objectifs communs
	•	Mettre en place le dépôt Git, Makefile, structure de projet.

Enzo
	•	Initialiser l’environnement (main loop, prompt avec readline).
	•	Implémenter la gestion du prompt + historique.
	•	Implémenter la détection de la fermeture (ctrl-D).
	•	Créer le parser de commande :
	•	Gestion des espaces, tokenisation.
	•	Gestion des guillemets simples et doubles.
	•	Début de la gestion des variables d’environnement ($VAR, $?).

⸻

Semaine 2 : Exécution de commandes simples + builtins

Wassim
	•	Recherche de binaire via PATH, exécution avec fork/execve.
	•	Implémentation de echo, pwd, env.
		- echo :
			- echo -n test
			- echo -n-n-n-n-n-n test
			- echo -nnnnnnnnn test
			- echo -nnnnonnnn test
	•	cd,
			- cd
			- cd -
			- cd .
			- cd ..
			- cd path
	•	export, unset,
	•	exit :
		- exit
		- exit 1
		- exit 0
		- exit 127
		- Il y a plein des edges cases a trouver / faire
		- exit 33333333333333333333333333333333333333333333333333333333
		- exit arg arg
		- exit blabla

	•	Affichage des erreurs pour builtins incorrects.
	•	Gestion de l’environnement interne (copie de envp).
	•	Gestion des builtins avec effet de bord :
nous deux
	•	Gestion des erreurs (commande introuvable, permissions, etc.).
⸻

Semaine 3 : Redirections & Pipes

Enzo
	•	Implémentation de redirections : <, >, >>.
	•	Implémentation du << (heredoc).

Wassim
	•	Implémentation des pipes : cmd1 | cmd2.
	•	Connexion correcte des entrées/sorties via dup2, pipe, etc.
	•	Gestion des processus enfants.

⸻

Semaine 4 : Signaux & finitions

Enzo
	•	Gestion des signaux :
	•	SIGINT (ctrl-C), SIGQUIT (ctrl-), etc.
	•	Gestion du signal global (une seule variable globale).
Wassim
	•	Comportement interactif comme bash.
tous les deux
	•	Finalisation de la gestion des variables ($VAR, $? dans quotes).
	•	Nettoyage mémoire (free, gestion erreurs).
	•	Tests globaux, correction bugs.

⸻

Semaine 5 (optionnelle) : Buffer, tests et robustesse

En commun
	•	Test massif : redirections + pipes + quotes + variables.
	•	Vérification des leaks avec Valgrind.
	•	Ajout de tests automatiques.
	•	Préparation à la soutenance.
