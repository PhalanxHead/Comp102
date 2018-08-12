# Handy Program Recommendations

This is by no means a definitive guide, and you can definitely ignore me if you want, but here's a list of stuff you might not have known about being a uni student, and a heap of useful programs you could use if you wanted.

## Good Stuff you get from Uni

Sooooo turns out being a student lends you a bunch of free or cheap software. Who knew? You should definitely leverage it. There's a bunch of stuff on the "Downloadable Software" page if you google "Unimelb free software" including MATLAB (ew), Mathematica, Microsoft Office, Windows licenses, Microsoft Azure, Wolfram Alpha Pro, Endnote, Lucidchart, and heaps more! But it doesn't list a few other perks, like the GitHub Student Pack (Which is worth a crazy amount of money in total), a half price Spotify subscription, subscriptions to things like Udemy, CodeCademy and the like. Honestly you should abuse it for all it's worth while you can :D Also included is a Unidays subscription and access to the Spotify Student discount. Try putting your uni email address into stuff, there's a good chance you'll get it free or discounted.

## Software

### Text Editors

Obviously to write code you're going to need a text editor. JEdit is one but it's just not nice to look at or use. Try the following:

- VS Code

Made by Microsoft, it's probably their best product. With extensive support for custom extensions and themes, it's nice to look at. It also lets you open a command line console (be it minGW or powershell or another) inside the program, minimising the need for alt-tabbing. Also did I mention it's free and super snappy?

- Atom

Atom is a github community project which is pretty similar to VS Code. Annoyingly it's a bit slower and just generally not as nice to use, at least in my experience. Most of the packages are a bit heavier and the inbuilt suite isn't as comprehensive. It has great git integration though, and it's definitely a huge step up from JEdit. It's also free and open source.

- Sublime

Sublime Text seems to be highly recommended by a lot of people, and I started out using it when I got to uni. It's fairly nice to use I guess, though it can be annoying at times. The extension manager isn't very friendly though, and it doesn't look as nice as the two above. It's technically not free, being on a WinRar style license where they'll never restrict access, just include annoying pop-ups every now and then. The full license is $70, but why pay for it?

- gedit

I remember doing a python tutorial in this back in high school. It has very few features, but it's not the worst thing ever. It's made by the guys at GNU, so it's good stuff, but it's super lightweight to the point of being kinda empty. It won't improve your workflow much tbh.

- Vim

Once upon a time in the 80s there was a text editor called Vi. As you go through uni you'll realise a good chunk of the faculty use Vi to edit text because it's so damned convenient! You never have to take your fingers off the home keys on your keyboard to shift the cursor, your home keys are mapped to move your cursor. It also runs inside your terminal window, so you can run it in ssh and edit code on a remote server without using scp or MobaXterm.
Vim is just the improved version of Vi, supporting an almost infinite amount of plugins and other customisability. It has a really really steep learning curve though. In fact, among novice software engineers there's a joke that the easiest way to exit vim is to restart your machine. 

Vim probably isn't better than most text editors in terms of functionality, but the way it's set up forces every user to become a power user, so anyone who tries it out tends to stick with it. Vim's free, I really like it, especially if I'm using a computer without a trackpoint, it means I can keep my hands on my keyboard.

- Emacs

Emacs is equally as old as Vim, and it's the bitter rival of it amongst older programmers. Vim uses the power of command keypresses to allow powerful combinations of text wrangling. Emacs uses the power of macros and keyboard shortcuts. Personally I never got around the emacs side of things, trying to read the default shortcuts was confusing and I didn't need the stress in my life tbh. Besides, vim has the advantage of being installed on almost all machines everywhere. Emacs usually needs to be installed.

That's not to say that Emacs is bad, if it's your jam then go for it! Most modern text editors use the emacs paradigm by default. Don't ask me for support for it though.

- Notepad

Every time you edit a file in Microsoft Notepad a puppy dies. Seriously. If I ever see you edit a program in this I'll consider asking you to leave the classroom. Please do not.

- Microsoft Word

This isn't a text editor, it's a word processor. Good luck is all I can say.

### Command Line Software

Let's be honest, MinGW sucks a bit, and windows CMD is not all that great, not having been changed since the early 90s and all. Here's some tools for Windows which might help you.

- Windows Subsystem for Linux (Or Bash for Windows)

So MinGW is the minimal GNU Windows environment, essentially letting you use Bash and GCC in Windows. Windows Subsystem for Linux implements a full linux environment on your Windows 10 machine. You can run programs like apt, more, less, vim, gcc, wc, and millions more just like a normal linux install. It's great! Instructions to get it here: https://docs.microsoft.com/en-us/windows/wsl/install-win10
Warning: You'll need to run `$sudo apt install build-essential` to get gcc installed.

- Windows Powershell

Powershell has a bunch of tools. If you ever want to be a Windows system admin, learning it isn't a bad idea. It has a surprising amount of control over your windows machine. That being said, it's not the best use of time ever probably.

- ConEmu

The windows command line looks like crap and you can't use tabs right? So ConEmu is your solution! It's a free console environment to change the look of your shell, and it lets you use tabs. It's pretty handy to be honest, can recommend.

- MobaXTerm

As alluded to last week, MobaXTerm is just plain convenient for connecting to remote servers. Would recommend, you'll be doing it a lot in the future, I'm not going to lie.

### Other Stuff

- Typora

So there's a language called Markdown which is widely used for writing nice looking notes and documents. In fact I'm writing this document in Markdown because it's convenient. The best editor for it I think seems to be Typora. It not only gives you a What-You-See-Is-What-You-Get editor style, but it lets you edit the source code as well. It has support for math blocks, code fences, and all kinds of good fun stuff, and has a bunch of good looking in-built themes already. Also it's free on all platforms, and it lets you convert to HTML, CSS, PDF and LaTeX if you want. It's really good for everything! (Also if there's more math there's a 90% chance I'll render it in markdown so using Typora will let you see it properly when you download it.)

- LaTeX

So like, long story short, Word sucks and lets you build a lot of really unflattering documents. The fonts look crappy, the interface sucks, if you move an image 3mm, 4 new pages appear and sirens sound in the distance. Also MS Word referencing sucks big time. If only you could code all of this somehow, and have the code generate a good looking document based off the code.

LaTeX steps in here. It's a typesetting program that takes a .tex file and outputs a beautiful document. All you need to do is some minor formatting in the code and type the content, and you have something print-worthy. It's the de-facto standard in academic literature publishing, it has amazing support and flexibility, and it's pretty easy to use. Referencing is easy and nice, and it has amazing support for tables and equations, it makes Word's equations look baby-like in comparison. Also it's free! Download Miktex and watch a few Youtube tutorials, because this is one environment you're gonna want to learn by the end of Uni.

- Git

By the end of uni, or the start of industry work, you're going to want to be able to use Git. Essentially, it's version control software, letting you take periodic backups of your docs or code, store the changes, then upload it to another server and share it amongst your computers. It's easy to use and really makes playing with different versions of your software so much easier. Also means if you lose your data, you lose hours instead of days of work. Honestly, learning Git ASAP is really going to help you in the long term, especially with group work.