**Switching active windows**
- i.e. going from a title screen to a new game
- **QStackedWidget**
  - This is essentially a stack of UI elements, you can switch 'pages' of the element when you want to replace one GUI with another without opening or closing a window
  - Can just drag a 'stackedWidget' GUI container onto the mainwindow.ui
    - In GUI debug mode you will see < and > arrows to change what page is active
    - The User will NOT see these arrows, this is just for debugging
  - https://www.youtube.com/watch?v=oFw-erSp3W8
  
 **Buttons**
- Add a button to the UI
- Right-click 'Add to Slot'
  - Select what method you want to implement
- This will automatically add the correct method implementation to the related UI's .cpp file
- Currently idk how to implement the same method for multiple buttons
  - Or how to instantiate a new Button class where we can just inherit the same logic from
  
**Adding Images**
- Easiest way is through labels
- *BUT* we have to add images to the project first, so they are local to the project, and not to our computers
  - I already created a resource folder with 'board.jpg', put any new images files in there
- In the GUI add a Label object
  - Right-click, 'change rich text' Hit the lil picture button and find the image you want
