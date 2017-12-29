

function TZIsObjEmpty(obj) {
  for(let k in obj) {
    return false;
  }
  return true;
}

function TZIsObjFilled(obj) {
  for(let k in obj) {
    return true;
  }
  return false;
}
