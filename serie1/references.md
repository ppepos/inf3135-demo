# Vim

Pour quelques commandes Vim additionnelles vous pouvez vous référer à ces *cheat sheets* ci:

 * [Cheat sheet de rtorr](http://vim.rtorr.com/)
 * [Cheat sheet graphique de viemu](http://www.viemu.com/a_vi_vim_graphical_cheat_sheet_tutorial.html)

# Markdown

Pour voir la syntaxe et le rendu des différents éléments Markdown vous pouvez vous référer au [guide exemple de
Github](https://guides.github.com/features/mastering-markdown/) et à ce
[rappel](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

# Git et clés SSH

Lors du premier laboratoire, vos utilisateurs sur malt n'avaient pas de clés SSH.
C'est ce qui vous empêchait de `git push` sur votre dépôt Gitlab.
Pour générer les clés et les ajouter à Gitlab, veuillez suivre les instructions suivantes.

   1. Connectez vous sur malt.
   2. Assurez vous que vos clés n'existent pas déjà et assurez-vous que ce répertoire est vide.

		ls -al ~/.ssh

   3. Créez vos clés SSH en utilisant la commande `ssh-keygen` et choisissez les options par défaut en appuyant sur `entrer` à chaque question SAUF quand l'utilitaire vous demande de choisir un mot de passe. Choisissez un bon mot de passe car ces clés seront votre façon de vous authentifier auprès de Gitlab et vous y placerez vos TPs.
   4. Vous devriez maintenant avoir au moins deux fichiers dans le répertoire `.ssh` de votre `home` (`~/.ssh/`). Les fichiers sont les suivants:

	* `id_rsa`: Votre clé privée (Ne la donnez à personne et conservez la bien! C'est votre identitée)
	* `id_rsa.pub`: Votre clé publique. C'est celle ci que vous distribuerez vous permettre aux autres de communiquer avec vous.

Vos clés SSH sont maintenant créées. Vous pouvez aller dans votre profil de Gitlab et y ajouter votre clé publique
dans la section `SSH Keys`. Une fois que vous aurez mis vos clés sur Gitlab, vous serez en mesure d'utiliser les
commandes git qui nécessitent accès à votre dépôt privé.

# Git

Voici deux tutoriaux qui expliquent très bien l'utilisation de git et les différentes commandes que git offre.

 * [Tutoriel de Github](https://try.github.io/levels/1/challenges/1)
 * [Tutoriaux d'Atlassian](https://www.atlassian.com/git/tutorials/)

