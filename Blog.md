# Building a Tetris Game to Learn C++

Welcome to my blog! In this series of writing unholy C++ code, I will be documenting my journey of building a Tetris game from scratch using C++. As a beginner in C++ and cocky developer, I wanted to bring my ego down a notch and work on a project that would put me in my place and help me pick up learning the intricacies of the language.

Tetris , In my opinion the greatest puzzle game ever made, a game simple enough for a toddler to play but at times complex enough to gives us adults the rush of setting a new record.

Throughout this blog, I will share my experiences, the challenges I faced, and the solutions I found while developing this game. I hope this series will be helpful for other beginners who are looking to learn C++ through practical projects. Let's dive into the world of game development and C++ programming together!

## Step 1: Setting Up the Project

The first step in building any game is to choose the way of implementation and setting up your workspace.

Coming from using pygame/arsina/tkinter ,I have no clue wtf i'm supposed to use here.

So like any developer who doesnt respect his own time or sanity i decided to not use any game engine and build the game from scratch using C++.

### Problem - 1: How to render this game?

In a nutshell a game is just a loop that updates 'n' times per second and renders the game state to the screen.So we show something then overwrite it something else 'n' times in a single second.

this is the basic idea of how games work.

Well the problem ,im a beginner and i have no clue how to even create a window to show shit.

A short google search later , i found the most recommended way was to use [Raylib](https://www.raylib.com) or [SFML](https://www.sfml-dev.org) ,after briefly looking at its name i choose to use [Raylib](raylib.com)

### Problem - 2: Rules of the game

Every game has certain number of rules, luckily for us tetris is a very simple game and widely available online.
The goal is to try to make a game as close to [Tetris](tetris.com)

### Problem - 3: IDE and Environment
  