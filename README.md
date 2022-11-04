# Virtware
Record/Play Virtual Sequence of Hardware Events.

## Status
*Under Development - Windows only (for now)*

## When it can be useful ?
The main goal is to be able to automate human routines, especially repetitive constant actions, for example:

- Imagine one day for some reason, you just want to delete all the +2000 Facebook friends request you have sent already, well, good luck spending hours deleting one by one (thanks to Facebook doesn't allow to delete all at once..), So, why not to record how to delete the first one, then play the routine to be performed for all of the other requests and let the computer repeat it meanwhile you are enjoying your root beer!

- Or, you want your computer to do something when you are not around, perhaps post something, message someone? you can schedule a series of actions (we call it here a routine) to be run at a certain time when you are not around.

- Or that fun shooting game you play that going afk can get you kicked or lost, what if you are able to record some routine of actions that you play when you are about to be afk, which will make you less dormant in the game..

> ... and many more scenarios ... 

## Target Features
- [ ] Record and play routines.
- [ ] Scripting language to directly perform hardware events in a simple and straightforward manner (example: `mouse move 20 20; key press a; mouse click left; key write "hello, world!" ...`)
- [ ] Create keyboard shortcuts to launch specific saved routines.
- [ ] Schedule routines to be played at a specific date and time.
- [ ] Use ML (like OpenCV) to make routines cognitive. to be able to recognize moving windows, fields, track objects to click or drag ...   
