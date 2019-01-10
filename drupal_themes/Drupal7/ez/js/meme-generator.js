var stage;
var text;
var hit;
var canvas;
var fontWeight = 'normal';
var background;
var selectedFont;
var dragger;
var hitResize;
var maxSize = 600;
var imageLoader;
var bgColor;
var textSize;
var input;


function init() {

  input = document.querySelector('#text');
  textSize = document.getElementById('text-size').options[document.getElementById('text-size').selectedIndex].value+'px';

  bgColor = document.getElementById('bg-color').value;


  imageLoader = document.getElementById('imageLoader');
  imageLoader.addEventListener('change', handleImage, false);

  canvas = document.getElementById('CanvasText');
  canvas.width = canvas.height = maxSize;

  stage = new createjs.Stage(canvas);

  background = new createjs.Shape();
  background.graphics.beginFill(bgColor).drawRect(0, 0, canvas.width, canvas.height);
  stage.addChild(background);
  stage.setChildIndex(background, 0);
  stage.enableMouseOver();

  addText(input.value);

  stage.update();
}

function addText(newText) {
  hit = new createjs.Shape();

  text = new createjs.Text(newText, "20px Arial", "#f00");
  text.textAlign = "center";
  text.x = text.y = 0;
  text.lineWidth = canvas.width;
  text.lineHeight = textSize*1.6;

  hit.graphics.beginFill("rgba(255,255,255,0.1)");
  hitResize = hit.graphics.drawRect((text.x - (text.getMeasuredWidth()/2)), 0, text.getMeasuredWidth(), text.getMeasuredHeight()).command;

	text.hitArea = hit;

  dragger = new createjs.Container();
  dragger.name = 'text';
  dragger.x = canvas.width/2;
  dragger.y = 100;
  dragger.addChild(text);
  dragger.cursor = 'move';
  dragger.setBounds(0, 0, text.getMeasuredWidth(), text.getMeasuredHeight());
  dragger.on("pressmove",function(evt) {
		// currentTarget will be the container that the event listener was added to:
		evt.currentTarget.x = evt.stageX;
		evt.currentTarget.y = evt.stageY;
		// make sure to redraw the stage to show the change:
		stage.update();
	});

  stage.addChild(dragger);
  stage.setChildIndex(dragger, 2);
  //stage.setChildIndex(dragger, 3);
}

function updateText() {
  text.text = input.value;
  resize();
  stage.update();
}

function updateTextAlign(align) {
  text.textAlign = align;
  resize();
  stage.update();
}

function swapShadow() {
  var shadow = document.getElementById('shadow');
  if (shadow.checked == true) {
    text.shadow = new createjs.Shadow("rgba(0,0,0,0.5)",1,1,3);
  } else {
    text.shadow = 0;
  }
  stage.update();
}

function setTextColor(picker) {
  text.color = '#'+picker.toString();
  document.getElementById(picker.targetElement.id).previousSibling.style.color = '#'+picker.toString();
  stage.update();
}

function setBgColor(picker) {
  var newColor = '#'+picker.toString();
  background.graphics.beginFill(newColor).drawRect(0, 0, canvas.width, canvas.height);
  document.getElementById(picker.targetElement.id).previousSibling.style.color = '#'+picker.toString();
  stage.update();
}

function changeFont() {
  selectedFont = document.querySelector('input[name=font]:checked');
  var bold = document.getElementById('bold');
  if (bold.checked == true) {
    fontWeight = 'bold';
  } else {
    fontWeight = 'normal';
  }
  var textSizeOption = document.getElementById('text-size');
  textSize = textSizeOption[textSizeOption.selectedIndex].value;
  text.font = fontWeight + ' ' + textSize + 'px ' + selectedFont.value;
  document.getElementById('text').setAttribute('class', 'form-control ' + selectedFont.id);
  var fontSelector = document.getElementById('current-font');
  fontSelector.className = selectedFont.id;
  fontSelector.innerHTML = selectedFont.value;
  text.lineHeight = textSize*1.6;
  resize();
  stage.update();
}

function handleImage(e){
    var reader = new FileReader();
    reader.onload = function(event){
        var img = new Image();
        img.onload = function(){
            var bitmap = new createjs.Bitmap(img.src);
          var imageWidth = bitmap.getBounds().width;
          if (imageWidth <= maxSize) {
            canvas.width = imageWidth;
            canvas.height = bitmap.getBounds().height;
            bitmap.setBounds(0, 0, imageWidth, bitmap.getBounds().height);
          } else {
            canvas.width = maxSize;
            canvas.height = bitmap.getBounds().height * (maxSize/imageWidth);
            bitmap.setTransform(0, 0, (maxSize/imageWidth), (canvas.height/bitmap.getBounds().height));
          }
          stage.addChild(bitmap);
          stage.setChildIndex(bitmap, 1);
          bitmap.name = "image";
          dragger.x = canvas.width/2;
        background.graphics.beginFill(bgColor).drawRect(0, 0, canvas.width, canvas.height);
          stage.update();
        }
        img.src = event.target.result;
    }
    reader.readAsDataURL(e.target.files[0]);
}

function exportImage() {
  var dataString = canvas.toDataURL("image/png");
  var link = document.createElement("a");
  link.download = 'image';
  link.href = dataString;
  link.click();
  return false;
}

function resize() {
  hitResize.w = text.getMeasuredWidth();
  hitResize.h = text.getMeasuredHeight();
  dragger.width = text.getMeasuredWidth();

  if (text.textAlign == 'center') {
    hitResize.x = text.x - text.getMeasuredWidth()/2;
  } else if (text.textAlign == 'right') {
    hitResize.x = text.getMeasuredWidth()*-1;
  } else {
    hitResize.x = text.x;
  }
}