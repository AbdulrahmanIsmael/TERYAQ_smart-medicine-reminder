import { useEffect, useState } from 'react';
import { database } from '../../firebase/firebase';
import { ref, set } from 'firebase/database';
import './time.scss';

function Time() {
  const [slotName, setSlotName] = useState('SLOT 1');
  const [inputs, setInputs] = useState({ hh: '', mm: '' });
  const [pills, setPills] = useState('');

  useEffect(() => {
    selectSlot();
  });

  //Select the slot which the user want to set time to
  function selectSlot() {
    const slotsBtns = document.querySelectorAll('.slot > button');
    slotsBtns.forEach(btn => {
      btn.addEventListener('click', e => {
        slotsBtns.forEach(b => b.classList.remove('active'));
        e.target.classList.add('active');
        setSlotName(e.target.innerText.toUpperCase());
      });
    });
  }

  // Error handling
  const showMsg = msgText => {
    const msg = document.querySelector('.msg');
    msg.innerHTML = msgText;
    setTimeout(() => {
      msg.classList.add('show-msg');
    }, 100);

    setTimeout(() => {
      msg.classList.remove('show-msg');
    }, 2200);
  };

  const setDate = (hh, mm) => {
    let literalDate = '';
    if (hh !== 0 && String(hh).length === 1) {
      literalDate = `0${hh}:`;
    } else {
      literalDate = `${hh}:`;
    }
    if (mm !== 0 && String(mm).length === 1) {
      literalDate += `0${mm}`;
    } else {
      literalDate += `${mm}`;
    }

    return literalDate;
  };

  const sendDataToDatabase = (med, date) => {
    const reference = ref(database, med);

    if (inputs.hh > 23) {
      inputs.hh = 23;
    }
    if (inputs.mm > 59) {
      inputs.mm = 59;
    }

    set(reference, {
      pills: Number(pills),
      time: { date, hours: Number(inputs.hh), minutes: Number(inputs.mm) },
    })
      .then(() => console.log('Time is set successfully'))
      .catch(error => console.log(error));
  };

  const setTime = e => {
    e.preventDefault();
    if (inputs.hh !== '' && inputs.mm !== '' && pills !== '') {
      const medNum = slotName.replace(/\w+ (\d)/, 'med$1');
      const date = setDate(inputs.hh, inputs.mm);
      sendDataToDatabase(medNum, date);
      showMsg('Time is set successfully');
    } else {
      showMsg('Please Fill all the required details!');
    }
  };
  return (
    <div className='time-center'>
      <div className='device-slots'>
        <div className='device-hole'>TERYAQ</div>
        <div className='g-1'>
          <div className='slot slot1'>
            <button className='active'>slot 1</button>
          </div>
        </div>
        <div className='g-2'>
          <div className='slot slot2'>
            <button>slot 2</button>
          </div>
          <div className='slot slot3'>
            <button>slot 3</button>
          </div>
        </div>
        <div className='g-3'>
          <div className='slot slot4'>
            <button>slot 4</button>
          </div>
        </div>
      </div>

      <form className='time-set'>
        <legend>{slotName}</legend>

        <fieldset className='time'>
          <legend>HH:MM</legend>

          <div>
            <input
              className='time-input'
              id='hh'
              type='number'
              min='0'
              max='23'
              placeholder='00'
              value={inputs.hh}
              onChange={e => setInputs({ ...inputs, hh: e.target.value })}
            />
            <div>:</div>
            <input
              className='time-input'
              id='mm'
              type='number'
              min='0'
              max='59'
              placeholder='00'
              value={inputs.mm}
              onChange={e => setInputs({ ...inputs, mm: e.target.value })}
            />
          </div>
        </fieldset>

        <div className='pills'>
          <label htmlFor='pills'>Pills</label>
          <input
            type='number'
            name='pills'
            id='pills'
            min='1'
            value={pills}
            onChange={e => setPills(e.target.value)}
          />
        </div>

        <input type='submit' value='Set Time' id='submit' onClick={setTime} />
      </form>

      <div className='msg'></div>
    </div>
  );
}

export default Time;
