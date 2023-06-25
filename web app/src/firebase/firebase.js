import { initializeApp } from 'firebase/app';
import { getDatabase } from 'firebase/database';
import { getAuth } from 'firebase/auth';

const firebaseConfig = {
  apiKey: 'AIzaSyCJpWGYVnGrKoHyHP5eHmVk9uIBptHw3dg',
  authDomain: 'test-1313a.firebaseapp.com',
  projectId: 'test-1313a',
  storageBucket: 'test-1313a.appspot.com',
  messagingSenderId: '519783323327',
  appId: '1:519783323327:web:43f99ff7fbdf670b20580a',
};

// initialize the Firebase app
const firebaseApp = initializeApp(firebaseConfig);

// get a reference to the database
const database = getDatabase(firebaseApp);

const auth = getAuth(firebaseApp);
export { database, auth };
