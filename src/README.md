This is the C++ source of the scoring engine.

Currently the following are done:
    1) Backdoors (checking either open port and file, or just file)
    2) Checking is root SSH login is enabled or not
    3) Checking the configuration of sudo (/etc/sudoers and /etc/sudoers.d/)
    4) Checking for rogue users

This will incorporate a scoring server. There are a couple options here:

    1) Have all the configuration on the client, and simply run a scoreboard on
    a server
    2) Have the configurations on a server, and send it (encrypted) to the
    client, and have the client check those and report back

I haven't decided what one I want to do yet. Right now, I guess I'll try to get
the first one done, since it seems the simplest.
