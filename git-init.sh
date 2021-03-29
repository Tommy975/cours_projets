#!/bin/bash
echo "# cours_projets" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/Tommy975/cours_projets.git
git push -u origin main
