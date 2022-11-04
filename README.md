# Virtware
Record/Play Virtual Sequence of Hardware Events.

## When it can be useful ?
The goal is to be able to automate human routines, especially repetitive constant actions for example:

- Deleting 1000 facebook friend requests, why not record how to delete the first one, then play the action to be performed for all of the other requests and let the computer repeat it ..

- You want your computer to do something when you are not around, perhaps post something, message someone? you can schedule a series of actions to be run at a certain time when you are not around..

- Delete discord messages, we know that discord does not allow you to delete all your messages at once.. we can record a series of actions (routine) to delete sent messages one by one. 

- That fun shooting game you play that going afk can get you kicked or lost, what if you are able to record some routine of actions that you play when you are about to be afk, which will make you less dormant in the game..

> ... and many more scenarios ... 

## Target Featues
- [ ] Record and play routines (aka VHR for Virtual Hardware Routine).
- [ ] Scripting language to directly perform hardware events in a simple and straightforward manner (example: `mouse move 20 20; key press A; mouse click left; ...`).
- [ ] Schedule routines to be played at a specific date and time.
- [ ] Create key shortcuts to launch specific saved routines.
- [ ] Use ML (like OpenCV) to make routines cognitive. 


### Terms
Routine: a sequence of hardware events is called a routine, example: `Move mouse to bottom left, click left mouse button, type Chrome, wait 2s, press Enter, wait 1s, type "Google.com", press Enter`.
